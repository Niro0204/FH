

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

    update({velocity}){
        if(this.image){
            this.draw()
            this.position.x += velocity.x
            this.position.y += velocity.y
            //console.log(this.velocity.x)
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
            x: 3,
            y: 0
        }

        this.invaders = []

        const rows = Math.floor(Math.random()* 5) +1
        const columns = Math.floor(Math.random() * 10) +1

        this.width = this.width = (columns - 1) * 40 + 30;
//columns * 35


        console.log(rows)
        console.log(columns)
        for(let i = 0; i < rows; i++){
            for(let j = 0; j < columns; j++) {
                this.invaders.push(new Invader({
                    position: {
                        x: j * 40,
                        y: i * 30
                    }
                }))
            }
            //console.log(this.invaders)
        }
    }

    update(){
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y

        this.velocity.y = 0
        if(this.position.x + this.width >= canvas.width || this.position.x <= 0){
            this.velocity.x = -this.velocity.x
            this.velocity.y = 30
        }

    }
}