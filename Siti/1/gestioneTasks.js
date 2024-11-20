let Tasks = [
    {"titolo": "Studiare italiano", "done": false},
    {"titolo": "Giocare a basket", "done": false},
    {"titolo": "Svegliarsi", "done": true},
    {"titolo": "Dormire", "done": true},
    {"titolo": "Cantare", "done": true},
    {"titolo": "Giocare", "done": true}
];

let elencoAzioniSvolte = document.getElementById("ul-done");
let elencoAzioniDaSvolgere = document.getElementById("ul-not-done");

let azioniSvolte = "";
let azioniDaSvolgere = "";
Tasks.forEach(task => {
    if(task.done) {
        azioniSvolte += "<li>" + task.titolo + "</li>";
    }
    else {
        azioniDaSvolgere += "<li>" + task.titolo + "</li>";
    }  
})

elencoAzioniSvolte.innerHTML = azioniSvolte;
elencoAzioniDaSvolgere.innerHTML = azioniDaSvolgere;