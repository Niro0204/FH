
class Player {

  constructor() {


      this.velocity={
          x: 0,
          y: 0
      }

      this.health = 100
      this.maxHealth = 100
      this.opacity = 1

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

      this.hitbox = {
          position: {
              x: 0,
              y: 0
          },
          width: this.width,
          height: this.height,
      }



  }



    draw() {

        c.globalAlpha = this.opacity
        // Bild zeichnen (wie gehabt)
        c.drawImage(
            this.image,
            this.position.x,
            this.position.y,
            this.width * scale,
            this.height * scale
        );

        this.updateHitbox()


    }


    update(){
      if(this.image){
          this.draw()
          this.position.x += this.velocity.x
          //console.log(this.velocity.x)
      }

        this.updateHealthBar()
        console.log("HEALTH: ",this.health)

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

    updateHitbox(){
        this.hitbox = {
            position: {
                x: this.position.x + 12,
                y: this.position.y + 17
            },
            width: this.width,
            height: this.height,
        }
    }


    takeDamage(amount) {
        this.health -= amount;
        if (this.health < 0) this.health = 0;
        this.updateHealthBar(); // Lebensanzeige aktualisieren
    }

    updateHealthBar() {
        const healthBarInner = document.querySelector("#health-bar-inner");
        const healthPercentage = (this.health / this.maxHealth) * 100;
        healthBarInner.style.width = `${healthPercentage}%`; // Passe die Breite des inneren Balkens an
    }

}

