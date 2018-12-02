var numeros = [];

function showEntrada() {
    let elementos = document.getElementById("inputValues").value;
    let fieldNameElement = document.getElementById("res");

    let tokens = elementos.split (" ");

    let j;
	for (j = 0; j < tokens.length; j++){
		numeros.push(parseInt(tokens[j]));
	}
	fieldNameElement.innerHTML = numeros [0];
}