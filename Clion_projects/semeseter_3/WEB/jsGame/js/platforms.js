

/*
class Platform extends Player{
    constructor({position, imageSrc, frameRate, frameBuffer, scale}) {
        super({position, imageSrc, frameRate, frameBuffer, scale});

    }
}*/
/*
const platforms = [
    { x: 0, y: 400, width: 700, height: 20 },
    { x: 300, y: 700, width: 400, height: 20 },
    { x: 800, y: 550, width: 350, height: 20 },
    { x: 1250, y: 400, width: 700, height: 20 },
    { x: 800, y: 250, width: 350, height: 20 },
    { x: 1100, y: 700, width: 600, height: 20 }]

*/
/*
function platformCollision(movingRect, staticRect) {
    // Rechtecke: { x, y, width, height }
    const horizontalOverlap = movingRect.position.x < staticRect.x + staticRect.width && movingRect.position.x + movingRect.width > staticRect.x;
    const verticalOverlap = movingRect.position.y < staticRect.y + staticRect.height && movingRect.position.y + movingRect.height > staticRect.y;

    if (horizontalOverlap && verticalOverlap) {
        // Prüfen, ob die Kollision "von oben" kommt
        const collisionFromAbove = movingRect.position.y + movingRect.height <= staticRect.y + staticRect.height;

        if (collisionFromAbove) {
            // Setze das bewegende Rechteck oben auf dem statischen Rechteck ab
            movingRect.position.y = staticRect.y - movingRect.height;
            player.velocity.y = 0;
            player.onPlatform = true
            console.log("Kollision von oben erkannt! Das bewegende Rechteck wurde abgesetzt.");
        }

        movingRect.position.y = staticRect.position.y - movingRect.position.height
        player.velocity.y = 0;
        player.onPlatform = true
        return true; // Es gab eine Kollision
    }

    return false; // Keine Kollision
}*/



/*
function platformCollision(player, platform) {
    const pBottom = player.position.y + player.height;
    const pTop = player.position.y;
    const platformTop = platform.y;
    const platformBottom = platform.y + platform.height;
    const pRight = player.position.x + player.width;
    const pLeft = player.position.x;

    const platformLeft = platform.x;
    const platformRight = platform.x + platform.width;

    if (
        pBottom <= platformTop && // Spieler berührt die Plattform
        pBottom + player.velocity.y >= platformTop && // Spieler bewegt sich Richtung Plattform
        player.position.x + player.width > platform.x && // Spieler ist horizontal über der Plattform
        player.position.x < platform.x + platform.width // Spieler ist horizontal innerhalb der Plattform
    ) {
        player.position.y = platformTop - player.height;
        player.velocity.y = 0;
        player.isJumping = false;
        player.onPlatform = true;
    }

    if (!player.onPlatform) {
        player.isJumping = true;
    }
}*/
/*

function platformCollision(player, platform) {
    const pBottom = player.hitbox.position.y + player.hitbox.height;
    const pTop = player.hitbox.position.y;
    const platformTop = platform.y;
    const platformBottom = platform.y + platform.height;
    const pRight = player.hitbox.position.x + player.hitbox.width;
    const pLeft = player.hitbox.position.x;

    const platformLeft = platform.x;
    const platformRight = platform.x + platform.width;

    if (
        pBottom <= platformTop && // Spieler berührt die Plattform
        //pBottom + player.velocity.y >= platformTop && // Spieler bewegt sich Richtung Plattform
        player.hitbox.position.x + player.hitbox.width > platform.x && // Spieler ist horizontal über der Plattform
        player.hitbox.position.x < platform.x + platform.width // Spieler ist horizontal innerhalb der Plattform
    ) {
        player.hitbox.position.y = platformTop - player.hitbox.height;
        player.velocity.y = 0;
        player.isJumping = false;
        player.onPlatform = true;
    }

    if (!player.onPlatform && !player.onGround) {
        player.isJumping = true;
    }

}*/
/*function platformCollision(player, platform) {
    const pBottom = player.hitbox.position.y + player.hitbox.height;
    const pTop = player.hitbox.position.y;
    const pRight = player.hitbox.position.x + player.hitbox.width;
    const pLeft = player.hitbox.position.x;

    const platformTop = platform.y;
    const platformBottom = platform.y + platform.height;
    const platformLeft = platform.x;
    const platformRight = platform.x + platform.width;

    // Prüfe, ob der Spieler von oben auf die Plattform fällt
    if (
        pBottom <= platformTop && // Spieler ist über der Plattform
        pBottom + player.velocity.y >= platformTop && // Spieler fällt nach unten Richtung Plattform
        pRight > platformLeft && // Spieler ist innerhalb der Plattform (rechts)
        pLeft < platformRight // Spieler ist innerhalb der Plattform (links)
    ) {
        // Spieler landet auf der Plattform
        player.hitbox.position.y = platformTop - player.hitbox.height;
        player.velocity.y = 0; // Fallgeschwindigkeit stoppen
        player.isJumping = false;
        return true;
    }

    return false; // Keine Kollision
}*/
/*
function platformCollision(player, platform){

    if(
        player.hitbox.position.y + player.hitbox.height >= platform.position.y &&
        player.velocity <= 0
    ){
        player.hitbox.position.y = platform.position.y - player.hitbox.height
        player.velocity = 0
        player.isJumping = false;
        player.onPlatform = true;
    }

    if (!player.onPlatform) {
        player.isJumping = true;
    }
}*/
/*
function platformCollision(player, platform) {

    if(player.hitbox.position.y + player.hitbox.height >= platform.y){

    }

}**/
/*
function platformCollision(player, platform) {
    player.onPlatform = false; // Standardmäßig ist der Spieler nicht auf einer Plattform

        // Überprüfen, ob der Spieler auf der Plattform ist
        const playerBottom = player.hitbox.position.y + player.hitbox.hight;
        const playerRight = player.hitbox.position.x + player.hitbox.width;
        const playerLeft = player.hitbox.position.x;

        const platformTop = platform.y;
        const platformBottom = platform.y + platform.height;
        const platformLeft = platform.x;
        const platformRight = platform.x + platform.width;

        if (
            playerBottom <= platformTop && // Spieler kommt von oben
            playerBottom + player.velocity.y >= platformTop && // Spieler bewegt sich nach unten
            playerRight > platformLeft && // Spieler ist horizontal auf der Plattform
            playerLeft < platformRight // Spieler ist horizontal auf der Plattform
        ) {
            // Spieler ist auf der Plattform
            player.velocity.y = 0; // Vertikale Geschwindigkeit stoppen
            player.position.y = platformTop - player.hitbox.hight; // Spieler genau auf die Plattform setzen
            player.onPlatform = true;
            player.isJumping = false; // Spieler darf erneut springen
        }


    // Falls der Spieler nicht auf einer Plattform ist, darf er fallen
    if (!player.onPlatform) {
        player.velocity.y += 1; // Gravitations-Effekt
    }

}*/
