
const canvas = document.querySelector("canvas")
console.log(canvas)
const c = canvas.getContext("2d")

const scoreDis = document.querySelector("#scoreDis")
//console.log(canvas)
//const c = canvas.getContext("2d")

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

function animate(){

    if(!game.active){
        return
    }

    c.clearRect(0, 0, canvas.width, canvas.height);

    requestAnimationFrame(animate)


    player.move()
    player.update()



    particles.forEach((particle, index) =>{

        if(particle.position.y - particle.radius >= canvas.height){
            particle.position.x = Math.random() * canvas.width
            particle.position.y =  -5 // Math.random() * canvas.height
        }

        if(particle.opacity <= 0){
            setTimeout(()=> {
                particles.splice(index, 1)
            },0)
        }else{
            particle.update()
        }
    })

    invaderProjectiles.forEach((invaderProjectile, index) => {
        if(invaderProjectile.position.y + invaderProjectile.height >= canvas.height){
            setTimeout(() => {
                invaderProjectiles.splice(index, 1)
            },0)
        }
        else{
            invaderProjectile.update()
        }
        // is player hit ?
        if(invaderProjectile.position.y + invaderProjectile.height <= player.hitbox.position.y &&
            invaderProjectile.position.x >= player.hitbox.position.x &&
            invaderProjectile.position.x + invaderProjectile.width <= player.hitbox.position.x + player.hitbox.width)
        {
            //console.log("Hit!!")
            player.takeDamage(10)

            if(player.health === 0){
                setTimeout(() => {
                    invaderProjectiles.splice(index, 1)
                    player.opacity = 0
                    game.over = true
                },0)
                createParticles({
                    object: player,
                    color: "red",
                    fades: true
                })
            }

        }

    })


    // deleting projectiles outside canvas
    projectiles.forEach((projectile, index) =>{
        if(projectile.position.y + projectile.radius <= 0){
            setTimeout(()=>{
                projectiles.splice(index,1)
            },0)
        }
        else{
            projectile.update()
        }

    })



    grids.forEach((grid,gridIndex) => {
        grid.update()

        // spawn invader projectiles
        if(frames % 200  === 0 && grid.invaders.length > 0){
            grid.invaders[Math.floor(Math.random() * grid.invaders.length)].shoot(invaderProjectiles)
        }
        grid.invaders.forEach((invader, i) =>{
            invader.update({velocity: grid.velocity})

            projectiles.forEach((projectile, j) =>{
                if (projectile.position.y - projectile.radius <=
                    invader.position.y + invader.height &&
                    projectile.position.x + projectile.radius >=
                    invader.position.x && projectile.position.x -
                    projectile.radius <= invader.position.x + invader.width&&
                    projectile.position.y + projectile.radius >=
                    invader.position.y)
                {



                    setTimeout(() => {
                        const invaderFound = grid.invaders.find(invader2 =>{return invader2 === invader})
                        const projectileFound = projectiles.find( projectile2 => projectile2 === projectile)

                        if(invaderFound && projectileFound ){

                            score += 100
                            console.log("SCORE: ",score)
                            scoreDis.innerHTML = score
                            // create explosion
                            createParticles({
                                object: invader,
                                color :"green",
                                fades: true
                            })

                            // removes invader and projectile when hit
                            grid.invaders.splice(i,1)
                            projectiles.splice(j,1)

                            if(grid.invaders.length > 0){
                                const firstInvader = grid.invaders[0]
                                const lastInvader = grid.invaders[grid.invaders.length - 1]

                                grid.width = lastInvader.position.x - firstInvader.position.x + lastInvader.width

                                grid.position.x = firstInvader.position.x
                            }
                            else{
                                grids.splice(gridIndex,1)
                            }
                        }

                    },0)
                }
            })
        })
    })

    // spawn invader grid
    if(frames % randomInterval === 0){
        grids.push(new Grid())
        randomInterval = Math.floor((Math.random() * 500) + 500)
        frames = 0
        //console.log(randomInterval)
    }



   // console.log(frames)
    frames ++
}

animate()