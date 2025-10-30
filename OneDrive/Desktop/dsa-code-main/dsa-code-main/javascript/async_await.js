function calculateSquare(x){
    return x*x;
}

function calculate(y){
    var promise=new Promise(function(resolve,reject){
        setTimeout(function(){
            var ss=calculateSquare(y);
            resolve(ss);
        },5000);
    });
return promise;
}

async function main(){
    var square1=await calculate(5);
    console.log("square of 5:"+square1);

    var square2=await calculate(10);
    console.log("sq of 10 is"+square2);
    console.log("the end, thank you");
}

main();

console.log('helll')