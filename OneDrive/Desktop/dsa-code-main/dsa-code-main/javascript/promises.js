function divide(dividend,divisor)
{
    var p=new Promise(function(doneNotifier,errorNotifier)
{
    setTimeout(function(){
        if(divisor==0){
            errorNotifier('can not divide by 0');
        }

        else{
            var r={
                quotient:Math.floor(dividend/divisor),
                remainder:dividend%divisor
            }
            doneNotifier(r);
        }
    },5000);
});
return p;
}

var a=10;
var b=0;

var promise=divide(a,b);

promise.then(function(result){
    var quotient=result.quotient;
    var remainder=result.remainder;
    console.log(`after dividing ${a} by ${b} quotient if ${quotient} & remainder is ${remainder}`);
}).catch(function(error){
    console.log(`problem: ${error}`);
}).then(function(){
    console.log("very cool");
}).then(function(){
    console.log("super cool");
});