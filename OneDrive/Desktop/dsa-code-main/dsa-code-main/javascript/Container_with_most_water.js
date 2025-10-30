/*
Problem Statement: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

var maxArea = function (height){
    let maxArea = 0;

    for(let a=0; a<height.length;a++){
        for(let b = a+1 ; b<height.length; b++){
            let area = ((Math.min(height[1],height[b]))*(b-a));

            maxArea = Math.max(maxArea,area);
        }
    }
    return maxArea;
}