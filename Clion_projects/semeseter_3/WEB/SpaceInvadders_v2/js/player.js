
class Player {

  constructor() {


      this.velocity={
          x: 0,
          y: 0
      }
      const image = new Image()
      image.src = "img/ships/Main Ship/Main Ship - Bases/PNGs/Main Ship - Base - Full health.png"
      image.onload = ()=> {
          this.image = image
          this.width = image.width
          this.height = image.height

          this.position={
              x: canvas.width / 2 - this.width,
              y: canvas.height - this.height - 50
          }
      }

  }


/*
  draw(){

      const scale = 1.5

      c.fillStyle = "green"
      c.fillRect(this.position.x , this.position.y ,this.width * scale, this.height * scale)

      c.fillStyle = "red"
      c.fillRect(this.position.x + (this.width * scale) / 2, this.position.y - (this.height * scale) / 2, 10, 10)

      c.save()
        c.translate(
            this.position.x * scale + this.width / 2,
            this.position.y * scale - this.height / 2
        )

        c.rotate(this.rotation)

      c.translate(
          - this.position.x * scale + this.width / 2,
          - this.position.y * scale - this.height / 2
      )

         c.drawImage(
              this.image,
              this.position.x,
              this.position.y,
              this.width * scale,
              this.height * scale
         )

      c.restore()
  }*/

    draw() {
        const scale = 1.5; // Gleicher Skalierungsfaktor wie für das Bild

        // Grünes Rechteck (angepasst an die Skalierung)
       /* c.fillStyle = "green";
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

        // Rotes Punkt (angepasst an die Skalierung)
        /*
        c.fillStyle = "red";
        c.fillRect(
            this.position.x + (this.width * scale) / 2 - 5, // Basierend auf unskalierter Breite
            this.position.y - (this.height * scale) / 2 + 60, // Basierend auf unskalierter Höhe
            10,
            10
        );

         */


    }


    update(){
      if(this.image){
          this.draw()
          this.position.x += this.velocity.x
          //console.log(this.velocity.x)
      }
  }

  move(){
      if(keys.a.pressed && player.position.x >= -5){
          this.velocity.x = -5

      }
      else if(keys.d.pressed && player.position.x + player.width <= canvas.width - 20){
          this.velocity.x = 5

      }
      else{
          this.velocity.x = 0

      }
  }

}