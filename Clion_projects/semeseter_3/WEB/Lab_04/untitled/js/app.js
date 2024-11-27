
const canvas = document.querySelector("canvas")

const c = canvas.getContext("2d")

const keyPress = {
    "a":false,
    "d":false,
    "w":false,
    "s":false
}

class Player {
    constructor() {
        this.width = 50
        this.height = 50
        this.color = "red"

        // TODO set player accordingly, using canvas.width, canvas.height
        this.position = {
            x:100,y:100
        }

        this.velocity = {
            x:0, y:0
        }
    }

    draw(){
        c.beginPath()
        c.rect(this.position.x,this.position.y, this.width,this.height)
        c.fillStyle = this.color
        c.fill()
    }

    update(){
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y

        this.draw()
    }

}

const player = new Player;


function animate(){
    c.clearRect(0,0, canvas.width, canvas.height)
    player.update()
    requestAnimationFrame(animate)
}

animate()


addEventListener("keydown",({key}) => {

    switch(key){
        case "a":
            keyPress.a = true
           // player.velocity.x = -2
            break
        case "d":
           // player.velocity.x = 2
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

    move()
})

addEventListener("keyup",({key}) => {
    console.log(key)
    switch(key){
        case "a":
            keyPress.a = false
            // player.velocity.x = -2
            break
        case "d":
            // player.velocity.x = 2
            keyPress.d = false
            break
        case "w":
            keyPress.w = false
            break
        case "s":
            keyPress.s = false
            break

    }
    move()
})

function move(){
    if(keyPress.a){
        player.velocity.x = -2
    }
    else if(keyPress.d){
        player.velocity.x = 2
    }
    else if(keyPress.w){
        player.velocity.y = 2
    }
    else if(keyPress.s){
        player.velocity.y = -2
    }

}
