
// Auswahl des Canvas-Elements
const canvas = document.querySelector("canvas")
console.log(canvas)
const c = canvas.getContext("2d")

// Elemente für den Game-Over-Bildschirm
const gameOverScreen = document.querySelector("#game-over-screen");
const finalScore = document.querySelector("#final-score");
const restartButton = document.querySelector("#restart-button");


const scoreDis = document.querySelector("#scoreDis")
//console.log(canvas)
//const c = canvas.getContext("2d")

// canvas Größe setzen
canvas.width = innerWidth
canvas.height = innerHeight

const keys = {
    a: {pressed: false},
    d: {pressed: false},
    space: {pressed: false}
}


const scale = 1.5

const projectiles = []
const invaderProjectiles = []
const particles = []

const player = new Player()
const grids = []

let frames = 0
let randomInterval = Math.floor((Math.random() * 500) + 500)
//console.log(randomInterval)
let game = {
    over: false,
    active: true

}
let score = 0


addEventListener("keydown", ({key})=>{

    if(game.over){
        return
    }

    switch(key){
        case 'a':
            //console.log("left")
            keys.a.pressed = true
            break
        case 'd':
            //console.log("right")
            keys.d.pressed = true
            break
        case ' ':
            //console.log("shoot")
            if(!keys.space.pressed){
                keys.space.pressed = true
                projectiles.push(new Projectile({
                    position: {
                        x: player.position.x + (player.width * scale) / 2 ,
                        y: player.position.y  - (player.height * scale) / 2 + 60,
                    },
                    velocity: {
                        x: 0,
                        y: -10
                    }
                }))
            }

            //console.log(projectiles)
            break
    }
})
addEventListener("keyup", ({key})=>{
    switch(key){
        case 'a':
            keys.a.pressed = false
            break
        case 'd':
            keys.d.pressed = false
            break
        case ' ':
            keys.space.pressed = false
            break
    }
})


for(let i = 0; i < 100; i++){
    particles.push(new Particle({
        position: {
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height
        },
        velocity: {
            x: 0,
            y: Math.random() * 0.5
        },
        radius: Math.random() * 2,
        color: "white"

    }))
}



function createParticles({object,color,fades})
{
    for(let i = 0; i < 15; i++){
        particles.push(new Particle({
            position: {
                x: object.position.x + object.width / 2,
                y: object.position.y + object.height / 2
            },
            velocity: {
                x: (Math.random() - 0.5) * 2,
                y: (Math.random() - 0.5) * 2
            },
            radius: Math.random() * 3,
            color: color,
            fades

        }))
    }
}



function animate() {
    if (!game.active) {
        return;
    }

    c.clearRect(0, 0, canvas.width, canvas.height);

    requestAnimationFrame(animate);

    player.move();
    player.update();

    // Partikel-Update
    particles.forEach((particle, index) => {
        if (particle.position.y - particle.radius >= canvas.height) {
            particle.position.x = Math.random() * canvas.width;
            particle.position.y = -5; // Math.random() * canvas.height
        }

        if (particle.opacity <= 0) {
            particles.splice(index, 1); // Sofortiges Entfernen ohne setTimeout
        } else {
            particle.update();
        }
    });

    // Invader-Projektile
    invaderProjectiles.forEach((invaderProjectile, index) => {
        // Entfernen von Projektile außerhalb der Leinwand
        if (invaderProjectile.position.y + invaderProjectile.height >= canvas.height) {
            invaderProjectiles.splice(index, 1);
        } else {
            invaderProjectile.update();
        }

        // Überprüfen, ob der Spieler getroffen wurde
        if (
            invaderProjectile.position.y + invaderProjectile.height >= player.hitbox.position.y &&
            invaderProjectile.position.y <= player.hitbox.position.y + player.hitbox.height &&
            invaderProjectile.position.x + invaderProjectile.width >= player.hitbox.position.x &&
            invaderProjectile.position.x <= player.hitbox.position.x + player.hitbox.width
        ) {
            if (!invaderProjectile.hit) {
                invaderProjectile.hit = true; // Sicherstellen, dass es nur einmal Schaden verursacht
                player.takeDamage(30);
                invaderProjectiles.splice(index, 1); // Projektile entfernen

                if (player.health === 0) {

                    player.opacity = 0;
                    game.over = true;
                    createParticles({
                        object: player,
                        color: "red",
                        fades: true
                    });

                    finalScore.textContent = score;
                    gameOverScreen.style.display = "block";
                }
            }
        }
    });

    // Spieler-Projektile
    projectiles.forEach((projectile, index) => {
        if (projectile.position.y + projectile.radius <= 0) {
            projectiles.splice(index, 1); // Sofortiges Entfernen ohne setTimeout
        } else {
            projectile.update();
        }
    });

    // Invader-Grids
    grids.forEach((grid, gridIndex) => {
        grid.update();

        if (frames % 200 === 0 && grid.invaders.length > 0) {
            grid.invaders[Math.floor(Math.random() * grid.invaders.length)].shoot(invaderProjectiles);
        }

        grid.invaders.forEach((invader, i) => {
            invader.update({ velocity: grid.velocity });

            projectiles.forEach((projectile, j) => {
                if (
                    projectile.position.y - projectile.radius <= invader.position.y + invader.height &&
                    projectile.position.x + projectile.radius >= invader.position.x &&
                    projectile.position.x - projectile.radius <= invader.position.x + invader.width &&
                    projectile.position.y + projectile.radius >= invader.position.y
                ) {
                    const invaderFound = grid.invaders.find(invader2 => invader2 === invader);
                    const projectileFound = projectiles.find(projectile2 => projectile2 === projectile);

                    if (invaderFound && projectileFound) {
                        score += 100;
                        scoreDis.innerHTML = score;
                        createParticles({
                            object: invader,
                            color: "green",
                            fades: true
                        });

                        grid.invaders.splice(i, 1);
                        projectiles.splice(j, 1);

                        if (grid.invaders.length > 0) {
                            const firstInvader = grid.invaders[0];
                            const lastInvader = grid.invaders[grid.invaders.length - 1];

                            grid.width = lastInvader.position.x - firstInvader.position.x + lastInvader.width;
                            grid.position.x = firstInvader.position.x;
                        } else {
                            grids.splice(gridIndex, 1);
                        }
                    }
                }
            });
        });
    });

    // Invader-Grids spawnen
    if (frames % randomInterval === 0) {
        grids.push(new Grid());
        randomInterval = Math.floor((Math.random() * 500) + 500);
        frames = 0;
    }

    frames++;
}

animate();

