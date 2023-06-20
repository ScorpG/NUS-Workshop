/* 
 *  P02 - p5.js WebSocket LED with Teachable Machine 
 *         Tensorflow.js model support.
 *  Creating a fancy interactive user interface 
 *  capable of communicating via WebSocket in p5.js
 *  Sound version - microphone
 *  
 */

const modelURL = 'https://teachablemachine.withgoogle.com/models/-K7DJI9vH/';

var classifier;
var label;
var previousLabel;
var ledValue;

var leftMove = false;
var rightMove = false;

function preload() {
    classifier = ml5.soundClassifier(modelURL + 'model.json');
}

function setup() {
    createCanvas(windowWidth,windowHeight);
    classifier.classify(gotResult);
  
}

function draw() {
    background(0);
    fill(255);
    textSize(32);
    textAlign(CENTER);
    text(label == ""? "I hear nothing!":"I hear " + label, width / 2, 100);
  
    stroke('red');
  
    if (leftMove) {
        fill(255);     
        strokeWeight(0); 
    }
    else {
        fill(0);
        strokeWeight(1);
    }
    // Draw a rectangle at (x, y, width, height , rounded corners).
    rect(10, windowHeight - 250 , (windowWidth/2) - 20, 200, 20);

    if (rightMove) {
        fill(255);     
        strokeWeight(0); 
    }
    else {
        fill(0);
        strokeWeight(1);
    }
    // Draw a rectangle at (x, y, width, height , rounded corners).
    rect((windowWidth/2) + 10, windowHeight - 250 , (windowWidth/2) - 20, 200, 20);
}


function gotResult(error, results) {
    if (error) {
        console.error(error);
        return;
    }
    label = String(results[0].label);
    console.log(label);
  
    if ((label != "Background Noise") && (previousLabel != label)) {
        if (label == "GO!") {
            leftMove = true;
            rightMove = true;  
        }
        else if (label == "STOP") {
            leftMove = false;
            rightMove = false;           
        } else if (label == "Right"){
          leftMove = false; 
          rightMove = true; 
        }else if (label == "Left"){
          leftMove = true; 
          rightMove = false; 
          
        }
    }
    previousLabel = label;
  
}