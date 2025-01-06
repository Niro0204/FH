class Projectile {

    constructor({position, velocity}) {

        this.position = position
        this.velocity = velocity

        this.radius = 4
    }

    draw() {
        // Zeichnet das Projektil
        c.beginPath()
        c.arc(this.position.x, this.position.y, this.radius, 0, Math.PI * 2)
        c.fillStyle = "red"
        c.fill()
        c.closePath()
    }

    update() {
        // aktualisiert die Position basierend auf der Geschwindigkeit
        this.draw()
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y
    }
}

class InvaderProjectile {

    constructor({position, velocity}) {

        this.position = position
        this.velocity = velocity

        this.width = 5
        this.height = 10
    }

    draw() {
        // Zeichnet das Projektil des Invaders
        c.fillStyle = "blue"
        c.fillRect(this.position.x, this.position.y, this.width, this.height)
    }

    update() {
        // aktualisiert Position basierend auf der Geschwindigkeit
        this.draw()
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y
    }
}

class Particle {

    constructor({position, velocity, radius, color, fades}) {

        this.position = position
        this.velocity = velocity

        this.radius = radius
        this.color = color

        this.opacity = 1

        // Flag, ob das Partikel verblassen soll
        this.fades = fades
    }

    draw() {
        // Zeichnet das partikel
        c.save() // Speichert den aktuellen Zustand des Canvas
        c.globalAlpha = this.opacity // Setzt die Deckkraft des Partikels
        c.beginPath()
        c.arc(this.position.x, this.position.y, this.radius, 0, Math.PI * 2)
        c.fillStyle = this.color
        c.fill()
        c.closePath()
        c.restore() // Stellt den vorherigen Zustand des Canvas wieder her
    }

    update() {
        // aktualisiert Position basierend auf der Geschwindigkeit
        this.draw()
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y

        // Verblasst das Partikel über die Zeit, falls aktiviert
        if (this.fades) {
            this.opacity -= 0.01
        }
    }
}
