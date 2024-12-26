

class Invader extends Player {

    constructor(position) {
        super(position);
        this.speed = 1
        this.dx = 1

        this.isDestroyed = false

    }

    draw(){
        if(this.isDestroyed){
            return
        }
        super.draw("green")
            //ctx.fillStyle = "green";
            //ctx.fillRect(this.position.x, this.position.y, this.width, this.height);
            this.position.x += this.dx;

            // Gegner an den Rand bewegen und zurückkehren lassen
            if (this.position.x + this.width > canvas.width || this.position.x < 0) {
                this.dx = -this.dx;
                this.position.y += 20; // Gegner nach unten bewegen
            }

    }

    detectCollision(index) {
        player.projectiles.forEach((p, pIndex) => {
            if (
                p.position.x < this.position.x + this.width &&
                p.position.x + p.width > this.position.x &&
                p.position.y < this.position.y + this.height &&
                p.position.y + p.height > this.position.y
            ) {
                this.isDestroyed = true
                // Kollision festgestellt: Projektile entfernen
                player.projectiles.splice(pIndex, 1);

                // Invader aus der Liste entfernen
                invaders.splice(index, 1);

                console.log("Invader zerstört!");
            }
        })
        if (invaders.length === 0) {
            console.log("Spiel gewonnen!");
            // Hier kannst du das Spiel stoppen oder eine neue Welle starten
        }
    }


}