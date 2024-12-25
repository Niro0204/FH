
const canvas = document.querySelector("canvas")

const c = canvas.getContext("2d")

const keyPress = {
    "a":false,
    "d":false,
    "w":false,
    "s":false
}

const GRAVITY = 0.5; // Gravitationskonstante

class Sprite{

    constructor({position, imageSrc}){
        this.position = position
        this.image = new Image()
        this.image.src = imageSrc
    }

    draw(){
        if(!this.image){
            return
        }
        c.drawImage(this.image,this.position.x, this.position.y)
    }

    update(){
        this.draw()
    }
}

class Ground {

    constructor(){
            this.x = 0,
            this.y = canvas.height - 30,
            this.width = canvas.width,
            this.height = 50,
            this.color = "green"
    }

    draw(){
        c.beginPath()
        c.rect(this.x,this.y,this.width,this.height)
        c.fillStyle = this.color
        c.fill()
    }


}

class Player {
    constructor(position) {
        this.width = 25
        this.height = 50
        this.color = "red"
        this.isJumping = false;


        this.position = position

        this.velocity = {
            x:0, y:1
        }

    }

    draw(){
        c.beginPath()
        c.rect(this.position.x,this.position.y, this.width,this.height)
        c.fillStyle = this.color
        c.fill()
    }

    update() {
        //this.velocity.y += GRAVITY;
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y
        this.velocity.y += GRAVITY

        // Kollision mit dem Boden
        if (this.position.y + this.height >= canvas.height - 30) {
            this.position.y = canvas.height - 30 - this.height // Spieler auf dem Boden "absetzen"
            this.velocity.y = 0 // Y-Geschwindigkeit auf 0 setzen
            this.isJumping = false
        }

        this.draw();
    }

    jump(){
        if(!this.isJumping){
            this.velocity.y = -14
            this.isJumping = true
        }
    }

}

const player = new Player({x: 25,y:100})
const background = new Sprite({
    position: {
        x:0,
        y:0
    },
    imageSrc: "img/background/m7/1.png"
})
const mountain = new Sprite({
    position: {
        x:0,
        y:0
    },
    imageSrc : "img/background/m7/2.png"
})
const floor = new Sprite({
    position: {
        x:0,
        y: canvas.height -30
    },
    imageSrc: "img/Tiles/1 Tiles/Tile_01.png"
})


const ground = new Ground;

// animation function
function animate(){

    c.clearRect(0,0, canvas.width, canvas.height)

    ground.draw()
    createFloor()

    c.save()
    c.scale(4, 3)
    background.update()
    mountain.update()
    c.restore()


    createFloor()

    move();
    player.update()
    requestAnimationFrame(animate)
}

// activating animation
animate()


addEventListener("keydown",({key}) => {

    switch(key){
        case "a":
            keyPress.a = true
            break
        case "d":
            keyPress.d = true
            break
        case "w":
                keyPress.w = true
            break
        case "s":
             keyPress.s = true
            break

    }
    console.log(key)

})

addEventListener("keyup",({key}) => {
    console.log(key)
    switch(key) {
        case "a":
            keyPress.a = false
            break
        case "d":
            keyPress.d = false
            break
        case "w":
            keyPress.w = false
            break
        case "s":
            keyPress.s = false
            break

    }
})

function move(){

    player.velocity.x=0
    //player.velocity.y=0

    if(keyPress.a){
        player.velocity.x = -2
    }
    if(keyPress.d){
        player.velocity.x = 2
    }
    if(keyPress.w){
        player.jump()
    }
    /*if(keyPress.s){
        player.velocity.y = 2
    }*/

}

function createFloor(){
    for (let x = 0; x < canvas.width; x += 32) {
        floor.position.x = x
        c.save()

        floor.update()
        c.restore()
    }
}
