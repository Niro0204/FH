
const canvas = document.querySelector("canvas")

const c = canvas.getContext("2d")

const keyPress = {
    "a":false,
    "d":false,
    "w":false,
    "s":false
}

const GRAVITY = 0.5; // Gravitationskonstante

const platforms = [
    { x: 0, y: 400, width: 700, height: 20 },
    { x: 300, y: 700, width: 400, height: 20 },
    { x: 800, y: 550, width: 350, height: 20 },
    { x: 1250, y: 400, width: 700, height: 20 },
    { x: 800, y: 250, width: 350, height: 20 },
    {x: 1100, y: 700, width: 600, height: 20}
]




const player = new Player({
    position: {x: 25,y:100 },
    imageSrc: "img/characters/Samurai_Archer/Idle.png"
})

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
const cliff = new Sprite({
    position: {
        x: 100,
        y: 50
    }
})


const ground = new Ground;

// animation function
function animate(){

    c.clearRect(0, 0, canvas.width, canvas.height);

    ground.draw()
    createFloor()
    c.save()
    c.scale(4, 3)
    background.draw()
    mountain.draw()
    c.restore()

    createFloor()
    drawPlatforms()
    move()
    player.update()
    console.log("on platform", player.onPlatform)
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
            player.canFall = true
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
    if(keyPress.s === true && player.onPlatform === true && player.isJumping === false && player.canFall === true ){
        player.position.y += 20
        player.canFall = false;
    }


}

function createFloor(){
    for (let x = 0; x < canvas.width; x += 32) {
        floor.position.x = x
        c.save()
        floor.update()
        c.restore()
    }
}

function drawPlatforms() {
    platforms.forEach(platform => {
        c.fillStyle = "brown"; // Beispiel: Farbe der Plattform
        c.fillRect(platform.x, platform.y, platform.width, platform.height);
    });
}

function platformCollision(player, platform) {
    const pBottom = player.position.y + player.height;
    const pTop = player.position.y;
    const platformTop = platform.y;
    const platformBottom = platform.y + platform.height;
    const pRight = player.position.x + player.width;
    const pLeft = player.position.x;

    const platformLeft = platform.x;
    const platformRight = platform.x + platform.width;

    /*if(keyPress.s === true){
        return
    }*/

    if (
        pBottom <= platformTop && // Spieler berührt die Plattform
        pBottom + player.velocity.y >= platformTop && // Spieler bewegt sich Richtung Plattform
        player.position.x + player.width > platform.x && // Spieler ist horizontal über der Plattform
        player.position.x < platform.x + platform.width // Spieler ist horizontal innerhalb der Plattform
    ) {
        // Spieler auf der Plattform absetzen
        player.position.y = platformTop - player.height;
        player.velocity.y = 0; // Bewegung nach unten stoppen
        player.isJumping = false;
        player.onPlatform = true;
        //break;
    }

// Falls keine Plattform unter den Füßen ist, fällt der Spieler
    if (!player.onPlatform) {
        player.isJumping = true;
    }
}


