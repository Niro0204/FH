

class Player{

    constructor({position}) {
        this.height = 50
        this.width = 25
        this.position = position
        this.speed = 5
        this.dx = 0

        this.projectiles = []
        this.projectileSpeed = 1

        this.health = 3

    }

    shootProjectile() {
        this.projectiles.push({
            position:{
                x: this.position.x + this.width / 2 - 2,
                y: this.position.y
            },
            width: 5,
            height: 10
        });

        console.log("projektil generiert!!")
    }

    drawProjectiles(){
        ctx.fillStyle = "red"
        this.projectiles.forEach(p => {
            ctx.fillStyle = "red"
            ctx.fillRect(p.position.x, p.position.y, p.width, p.height)
            p.position.y -= this.projectileSpeed; // Projektile bewegen
        })

        console.log("projektil fliegt")
    }

   draw(color = "white") {
        ctx.fillStyle = color
        ctx.fillRect(this.position.x, this.position.y, this.width, this.height)
        console.log("player drawn!")
    }

    move(){
        this.position.x += this.dx
    }




}