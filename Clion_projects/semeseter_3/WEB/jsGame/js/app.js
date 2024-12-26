const canvas = document.querySelector("canvas");
const c = canvas.getContext("2d");

const keyPress = {
    "a": false,
    "d": false,
    "w": false,
    "s": false,
}

const GRAVITY = 0.5;
const player = new Player({
    position: { x: 500, y: 550 },
    imageSrc: "img/characters/Samurai_Archer/Idle.png",
    frameRate: 9
})
console.log("player wird geladen",player.image.src)
const background = new Sprite({
    position: { x: 0, y: 0 },
    imageSrc: "img/background/m7/1.png"
})
const mountain = new Sprite({
    position: { x: 0, y: 0 },
    imageSrc: "img/background/m7/2.png"
})
console.log("bergpfad: ", mountain.image.src)
const floor = new Sprite({
    position: { x: 0, y: canvas.height - 30 },
    imageSrc: "img/Tiles/1 Tiles/Tile_01.png"
})
const ground = new Ground;


function animate() {
    c.clearRect(0, 0, canvas.width, canvas.height);

    ground.draw()
    //createFloor()
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

animate();

addEventListener("keydown", ({ key }) => {
    switch (key) {
        case "a": keyPress.a = true; break;
        case "d": keyPress.d = true; break;
        case "w": keyPress.w = true; break;
        case "s": keyPress.s = true; break;
    }
});

addEventListener("keyup", ({ key }) => {
    switch (key) {
        case "a": keyPress.a = false; break;
        case "d": keyPress.d = false; break;
        case "w": keyPress.w = false; break;
        case "s": keyPress.s = false;  player.canFall = true; break;
    }
    console.log(key)
});

/*

function move() {
    player.velocity.x = 0;
    if (keyPress.a) player.velocity.x = -2
    if (keyPress.d) player.velocity.x = 2
    if (keyPress.w) player.velocity.y = player.jump()
    if(keyPress.s === true && player.onPlatform === true && player.isJumping === false && player.canFall === true ){
            player.position.y += 20
            player.canFall = false;
    }

}*/

function move() {
    player.velocity.x = 0;
    if (keyPress.a) player.velocity.x = -2;
    if (keyPress.d) player.velocity.x = 2;

    if (keyPress.w  /*&& !player.isJumping && (player.onGround || player.onPlatform)*/) {
        player.jump();// player.jump(); // Startet den Sprung, wenn der Spieler auf dem Boden oder einer Plattform ist
    }
}
/*
    if (keyPress.s && player.onPlatform && !player.isJumping && player.canFall) {
           ;
        //player.position.y += 20;  // Wenn der Spieler auf einer Plattform ist und nach unten drückt, fällt er
        //player.canFall = false;  // Setzt eine Sperre, damit der Spieler nicht sofort wieder nach unten fällt
    }
}
*/

function createFloor() {
    for (let x = 0; x < canvas.width; x += 32) {
        floor.position.x = x
        c.save()
        floor.draw()
        c.restore()
    }
}

function drawPlatforms() {
    platforms.forEach(platform => {
        c.fillStyle = "brown";
        c.fillRect(platform.position.x, platform.position.y, platform.width, platform.height);
    });
}
