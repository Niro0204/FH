
const canvas = document.querySelector("canvas")
console.log(canvas)
const c = canvas.getContext("2d")

canvas.width = innerWidth
canvas.height = innerHeight

const keys = {
    a: {pressed: false},
    d: {pressed: false},
    space: {pressed: false}
}

const scale = 1.5

const projectiles = []


const player = new Player()
const grids = []




addEventListener("keydown", ({key})=>{
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

let frames = 0
let randomInterval = Math.floor((Math.random() * 500) + 500)
console.log(randomInterval)

function animate(){
    c.clearRect(0, 0, canvas.width, canvas.height);

    requestAnimationFrame(animate)


    player.move()
    player.update()


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

    grids.forEach(grid => {
        grid.update()
        grid.invaders.forEach((invader, i) =>{
            invader.update({velocity: grid.velocity})

            projectiles.forEach((projectile, j) =>{
                if (projectile.position.y - projectile.radius <=
                    invader.position.y + invader.height &&
                    projectile.position.x + projectile.radius >=
                    invader.position.x && projectile.position.x -
                    projectile.radius <= invader.position.x &&
                    projectile.position.y + projectile.radius >=
                    invader.position.y){

                    setTimeout(() => {
                        const invaderFound = grid.invaders.find(invader2 =>{
                            return invader2 === invader
                        })

                        if(invaderFound ){
                            grid.invaders.splice(i,1)
                            projectiles.splice(j,1)
                        }

                    },0)
                }
            })
        })
    })

    if(frames % randomInterval === 0){
        grids.push(new Grid())
        randomInterval = Math.floor((Math.random() * 500) + 500)
        frames = 0
        console.log(randomInterval)
    }

   // console.log(frames)
    frames ++
}

animate()