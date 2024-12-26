class Player extends Sprite {
    constructor(position,imageSrc) {
        super({position, imageSrc})
        this.width = 25
        this.height = 50
        this.color = "red"
        this.isJumping = false
        this.onPlatform = false
        this.canFall = true


        this.position = position

        this.velocity = {
            x:0, y:1
        }

    }

    /*draw(){
        c.beginPath()
        c.rect(this.position.x,this.position.y, this.width,this.height)
        c.fillStyle = this.color
        c.fill()
    }*/

    update() {
        //this.velocity.y += GRAVITY;
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y
        this.velocity.y += GRAVITY

        // Kollision mit dem Boden
        if (this.position.y + this.height >= canvas.height - 30) {
            this.position.y = canvas.height - 30 - this.height // Spieler auf dem Boden "absetzen"
            this.velocity.y = 0 // Y-Geschwindigkeit auf 0 setzen
            this.isJumping = false
        }

        platforms.forEach(platform => {
            platformCollision(this, platform);
        });

        this.draw();
    }

    jump(){
        if(!this.isJumping){
            this.velocity.y = -15
            this.isJumping = true
        }
    }

}