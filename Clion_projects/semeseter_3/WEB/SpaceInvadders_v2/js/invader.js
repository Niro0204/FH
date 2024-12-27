

class Invader {

    constructor({position}) {


        this.velocity={
            x: 0,
            y: 0
        }
        const image = new Image()
        image.src = "img/invaders/defaultInvader.png"
        image.onload = ()=> {
            this.image = image
            this.width = image.width
            this.height = image.height

            this.position={
                x: position.x,
                y: position.y
            }
        }

    }

    draw() {
        const scale = 2.5 ; // Gleicher Skalierungsfaktor wie für das Bild

        // Grünes Rechteck (angepasst an die Skalierung)
        /*
        c.fillStyle = "green";
        c.fillRect(
            this.position.x,
            this.position.y,
            this.width * scale, // Skaliere Breite
            this.height * scale // Skaliere Höhe
        );

         */

        // Bild zeichnen (wie gehabt)
        c.drawImage(
            this.image,
            this.position.x,
            this.position.y,
            this.width * scale,
            this.height * scale
        );

    }

    update(){
        if(this.image){
            this.draw()
            this.position.x += this.velocity.x
            this.position.y += this.velocity.y
            console.log(this.velocity.x)
        }
    }

}

class Grid{

    constructor() {
        this.position= {
            x:0,
            y:0
        }

        this.velocity = {
            x: 0,
            y: 0
        }

        this.invaders = []

       for(let i = 0; i < 5; i++){
            for(let j = 0; j < 10; j++) {
                this.invaders.push(new Invader({
                    position: {
                        x: j * 40,
                        y: i * 30
                    }
                }))
            }
            console.log(this.invaders)
       }
    }

    update(){}
}