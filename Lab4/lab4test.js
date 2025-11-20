let myArr = [1, 2, 2];
// let myOBJ = {
//   ageeo, myeje, haehl
// }

// let stsaop = new myOBJ();

// console.log(stsaop);

let Cat = {
  name: "Catteo",
  age: 0,
  color: "white"
}

let minimeow = Cat;
minimeow.age = 3;
console.log(minimeow);

class CatClass {
  constructor(name, age, color) {
    this.name = name;
    this.age = age;
    this.color = color;
  }
}

let macromeow = new CatClass("Macro", 5, "black");

console.log(`There is the CatClass: ${macromeow.name} ${macromeow.age}`);

