class Sprite{

    constructor({position, imageSrc}){
        this.position = position
        this.image = new Image()
        this.image.src = imageSrc
    }

    draw(){
        if(!this.image){
            return
        }
        c.drawImage(this.image,this.position.x, this.position.y)
    }

    update(){
        this.draw()
    }
}

class Ground {

    constructor(){
        this.x = 0,
            this.y = canvas.height - 30,
            this.width = canvas.width,
            this.height = 50,
            this.color = "green"
    }

    draw(){
        c.beginPath()
        c.rect(this.x,this.y,this.width,this.height)
        c.fillStyle = this.color
        c.fill()
    }


}