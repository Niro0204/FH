
const canvas = document.querySelector("canvas")

const c = canvas.getContext("2d")

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

}

const player = new Player;
player.draw()
