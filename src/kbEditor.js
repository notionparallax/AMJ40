fs = require('fs')

function getJSON(filePath){
  theJSON = JSON.parse(fs.readFileSync(filePath).toString());
  return theJSON;
}

console.log("we're here" + process.env.PWD);
var path = '/projects/git/AMJ40/src/'
var layout  = getJSON(process.env.PWD + path + 'keyboard-layout.json');
var charMap = getJSON(process.env.PWD + path + 'keyMapping.json');

var mainLayer = [];
var greenLayer= [];
var blueLayer = [];
var pinkLayer = [];

var main = 4;
var green= 2;
var blue = 0;
var pink = 10;

var symbolSet = new Set();

for (var j = 0; j < layout.length; j++) {
    var row = layout[j];

    mainLayer[j] = [];
    greenLayer[j]= [];
    blueLayer[j] = [];
    pinkLayer[j] = [];

    for (var i = 0; i < row.length; i++) {
        var key = row[i];
        if (typeof(key) == "string") {
            keyVals = key.split("\n");
            mainLayer[j].push(keyVals[main]);
            greenLayer[j].push(keyVals[green]);
            blueLayer[j].push(keyVals[blue]);
            pinkLayer[j].push(keyVals[pink]);
            for (var k = keyVals.length - 1; k >= 0; k--) {
              symbolSet.add(keyVals[k]);
            }
        }
    }
}

////get null char mapping
// var charMappingArray = Array.from(symbolSet).sort();
// var charMapping = {};
// for (var i = 0; i < charMappingArray.length; i++) {
//   charMapping[charMappingArray[i]] = charMappingArray[i]
// }
// console.log(charMapping);

var layers = [{layer: mainLayer,  name:"main Layer"},
              {layer: greenLayer, name:"green Layer (FN0)"},
              {layer: blueLayer,  name:"blue Layer (FN1)"},
              {layer: pinkLayer,  name:"pink Layer (FN0 + FN1)"}
             ];

for (var k = 0; k < layers.length; k++) {
    var layer = layers[k].layer;
    var name  = layers[k].name;
    var boardRepresentation = "";
    var keymap_c = "KEYMAP(\n";

    for (var i = 0; i < layer.length; i++) {
        var repKey, cKey;
        var row = layer[i];
        var rowText = "|"
        var keymapText = "      "
        for (var j = 0; j < row.length; j++) {
          var key = row[j]
            if (key == undefined || key == "") {
              repKey = " ";
              cKey   = "TRNS";
            } else {
              repKey = charMap[key];
              cKey   = charMap[key];
            }
            rowText    += (" " + repKey + " |");
            keymapText += (cKey + ",  ");
        }

        var divider = new Array(rowText.length + 1).join("-");
        if (i == 0) {
            boardRepresentation += divider+"\n";
        }
        boardRepresentation += rowText+"\n";
        boardRepresentation += divider+"\n";

        keymap_c += keymapText += "\\\n"
    }
    console.log("******\n"+name+"\n");
    console.log(layers[k].layer += "\n");
    console.log(boardRepresentation+"\n");
    console.log(keymap_c += ")\n******\n");
}
console.log(mainLayer);
