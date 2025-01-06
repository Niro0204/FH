class Invader {
    constructor({ position }) {

        this.velocity = {
            x: 0,
            y: 0
        };

        // Bild des Invaders laden
        const image = new Image()
        image.src = "img/invaders/defaultInvader.png"
        image.onload = () => {
            // größe wird nur gesetzt wenn das bild geladen ist
            this.image = image
            this.width = image.width
            this.height = image.height

            // Anfangsposition des Invaders
            this.position = {
                x: position.x,
                y: position.y
            };
        };
    }

    // Zeichne den Invader auf das Canvas
    draw() {
        const scale = 2.5; // Skalierung für die Größe des Invaders


        // Zeichne den invader
        c.drawImage(
            this.image,
            this.position.x,
            this.position.y,
            this.width * scale,
            this.height * scale
        );
    }

    // Aktualisiere die Position des Invaders
    update({ velocity }) {
        if (this.image) {
            this.draw()

            // Aktualisiere die Position
            this.position.x += velocity.x
            this.position.y += velocity.y
        }
    }

    // Invader schießt ein Projektil
    shoot(invaderProjectiles) {
        // Erstelle ein neues Projektil
        invaderProjectiles.push(new InvaderProjectile({
            position: {
                x: this.position.x + this.width / 2,
                y: this.position.y + this.height
            },
            velocity: {
                x: 0,
                y: 4
            }
        }));
    }
}

class Grid {
    constructor() {

        this.position = {
            x: 0,
            y: 0
        }

        this.velocity = {
            x: 3,
            y: 0
        }

        // Array, welches alle invader hält
        this.invaders = []

        // Zufällige Anzahl von Reihen und Spalten
        const rows = Math.floor(Math.random() * 5) + 1
        const columns = Math.floor(Math.random() * 10) + 1

        // Breite des Grids basierend auf der Anzahl der Spalten
        this.width = (columns - 1) * 40 + 30

        console.log(rows)
        console.log(columns)

        // Fülle das Grid mit Invaders
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < columns; j++) {
                this.invaders.push(new Invader({
                    position: {
                        x: j * 40,
                        y: i * 30
                    }
                }))
            }
        }
    }

    // Aktualisiere die Position des gesamten Grids
    update() {
        // Bewegung des Grids
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y

        // Setze vertikale Bewegung zurück
        this.velocity.y = 0

        // Ändere Richtung und bewege das Grid nach unten, wenn es die Bildschirmgrenzen erreicht
        if (this.position.x + this.width >= canvas.width || this.position.x <= 0) {
            this.velocity.x = -this.velocity.x
            this.velocity.y = 30;
        }
    }
}
