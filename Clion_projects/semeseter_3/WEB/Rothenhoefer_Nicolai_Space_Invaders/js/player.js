class Player {
    constructor() {

        this.velocity = {
            x: 0,
            y: 0
        };


        this.health = 100
        this.maxHealth = 100
        this.opacity = 1

        // Bild des Spielers laden
        const image = new Image()
        image.src = "img/ships/Main Ship/Main Ship - Bases/PNGs/Main Ship - Base - Full health.png"
        image.onload = () => {
            // größe des spielers an bild anpassen
            this.image = image;
            this.width = image.width;
            this.height = image.height

            // Anfangsposition des Spielers
            this.position = {
                x: canvas.width / 2 - this.width,
                y: canvas.height - this.height - 50
            };
        };

        // Hitbox zur Kollisionserkennung
        this.hitbox = {
            position: {
                x: 0,
                y: 0
            },
            width: this.width,
            height: this.height
        };
    }

    // Zeichne den Spieler auf das Canvas
    draw() {
        c.globalAlpha = this.opacity
        c.drawImage(
            this.image,
            this.position.x,
            this.position.y,
            this.width * scale,
            this.height * scale
        );

        // Aktualisiere die Hitbox nach dem Zeichnen
        this.updateHitbox();
    }

    // Aktualisiere die position des
    update() {
        if (this.image) { // Zeichne den Spieler nur wenn das Bild geladen ist
            this.draw()
            this.position.x += this.velocity.x
        }

        // Aktualisiere die Lebensanzeige
        this.updateHealthBar()
        //console.log("HEALTH: ", this.health);
    }

    // Bewegung des Spielers basierend auf gedrückten Tasten
    move() {
        if(keys.a.pressed && keys.d.pressed){
            this.velocity.x=0
        }
        else if (keys.a.pressed && player.position.x >= -5) {
            this.velocity.x = -5
        }
        else if (keys.d.pressed && player.position.x + player.width <= canvas.width - 20) {
            this.velocity.x = 5
        }
        else {
            this.velocity.x = 0
        }
    }

    // Aktualisiere die Hitbox basierend auf der Spielerposition
    updateHitbox() {
        this.hitbox = {
            position: {
                x: this.position.x + 12, // genau an player angepasst
                y: this.position.y + 17
            },
            width: this.width,
            height: this.height
        };
    }

    // Reduziere Leben des Spielers
    takeDamage(amount) {
        this.health -= amount;
        if (this.health < 0) this.health = 0
        this.updateHealthBar()
    }

    // Aktualisiere die Lebensanzeige im DOM
    updateHealthBar() {
        const healthBarInner = document.querySelector("#health-bar-inner")
        const healthPercentage = (this.health / this.maxHealth) * 100
        healthBarInner.style.width = `${healthPercentage}%`
    }
}
