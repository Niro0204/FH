
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



    draw() {
        const scale = 1.5; // Gleicher Skalierungsfaktor wie für das Bild


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