const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");

const player = new Player({
    position: {
        x: canvas.width / 2 - 25,
        y: canvas.height - 50
    }
})

const invaders = []

for (let i = 0; i < 5; i++) {
    invaders.push(new Invader({
        position: {
            x: 50 + i * 100, // Abstand zwischen Invadern
            y: 50
        }
    }));
}

const invader = new Invader({
    position: {
        x: 50,
        y: 50
    }

})


const keyPressed = {};

document.addEventListener("keydown", (e) => {
    keyPressed[e.key] = true;
    if (e.key === " ") player.shootProjectile();
});
document.addEventListener("keyup", (e) => {
    keyPressed[e.key] = false;
});

player.move = function() {
    if (keyPressed["ArrowRight"]) this.dx = this.speed;
    else if (keyPressed["ArrowLeft"]) this.dx = -this.speed;
    else this.dx = 0;
    this.position.x += this.dx;
};


// Zeichne alles
function animate() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    player.draw();
    player.drawProjectiles();

    invaders.forEach((invader, index) => {
        invader.draw();
        invader.detectCollision(index);
    });

    invader.detectCollision();

    // Spielerbewegung
    player.move()

    // Grenzen für die Spielfigur
    if (player.x < 0) player.x = 0;
    if (player.x + player.width > canvas.width) player.x = canvas.width - player.width;

    requestAnimationFrame(animate); // Animation fortsetzen
}

// Spiel starten
animate();
