var numeros = [];
var color = [];
var animar = false;

function showEntrada() {
    let elementos = document.getElementById("inputValues").value;
    let fieldNameElement = document.getElementById("res");

    let tokens = elementos.split (" ");

    let j;
	for (j = 0; j < tokens.length; j++){
		numeros.push(parseInt(tokens[j]));
	}
	fieldNameElement.innerHTML = numeros [0];
	animar = true;
	noLoop();
}


function setup() 
{
  createCanvas(700, 400);  
}

function draw() 
{ 
	if (animar){
		let j;
		drawArray (numeros, 10, 10, 40);
		animar = false;
	} 
}

function drawArray (arr, x, y, size){
	let i;
	let posx;
	for (i = 0; i < arr.length; i++){
		posx = x + size * i; 
		rect (posx, y, size, size);
		stroke(125);
		text (numeros[i], posx + (size/2), y + (size/2));
		stroke(0);
	}
}