const getUrl = "https://web.its.fh-salzburg.ac.at/chat/get/messages/"
const postUrl = "https://web.its.fh-salzburg.ac.at/chat/post/message/"
const formElem = document.getElementById("chat-form")
const messageContainer = document.getElementById("chat-messages")
const displayedIds = []

function postMessage(name, message) {
    const http = new XMLHttpRequest()
    http.open("POST", postUrl, true)
    http.setRequestHeader("Content-type","application/x-www-form-urlencoded")
    const params = "name=" + name + "&message=" + message
    http.send(params)
}

function submitForm(event) {
    event.preventDefault()
    const messageElem = formElem.querySelector('input[name="message"]')
    const message = messageElem.value
    const name = formElem.querySelector('input[name="name"]').value
    if (name !== "" && message !== "") {
        postMessage(name, message)
        messageElem.value = ""
        messageElem.focus()
    }

}

function fetchAndUpdateMessages() {
    fetch(getUrl)
        .then(response => response.json())
        .then(data => {
            const msgs = data.messages
            msgs.sort((a,b) => new Date(a.timestamp * 1000).getTime() - new Date(b.timestamp * 1000).getTime());
            msgs.forEach(message => {
                if (displayedIds.includes(message.id)) {
                    return
                }
                const timestamp = new Date(message.timestamp * 1000)
                const timeString = `(${timestamp.getHours() < 10 ? '0' : ''}${timestamp.getHours()}:${timestamp.getMinutes() < 10 ? '0' : ''}${timestamp.getMinutes()})`

                const messageElem = document.createElement("p")
                const timeElem = document.createElement("span")
                timeElem.innerHTML = timeString + " "
                const nameElem = document.createElement("span")
                nameElem.innerHTML = message.name + ": "
                const messageTextElem = document.createElement("span")
                messageTextElem.innerHTML = message.message

                messageElem.appendChild(timeElem)
                messageElem.appendChild(nameElem)
                messageElem.appendChild(messageTextElem)

                messageContainer.appendChild(messageElem)
                messageContainer.scrollTop = messageContainer.scrollHeight

                displayedIds.push(message.id)
            })
        })
        .catch(error => {
            console.error("Error fetching data:", error)
        })

}

fetchAndUpdateMessages()
setInterval(fetchAndUpdateMessages, 1000)

formElem.addEventListener("submit", submitForm)
