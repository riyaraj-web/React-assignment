/**
 * @param {string} s
 * @return {number}
 */
var  = function(s) {
    let ans = 0;
    let open = 0;
    let close = 0;
    let n = s.length;

    // Left to right pass
    for (let i = 0; i < n; i++) {
        if (s[i] === '(') {
            open++;
        } else {
            close++;
        }

        if (open === close) {
            ans = Math.max(ans, 2 * close);
        } else if (close > open) {
            open = close = 0;
        }
    }

    open = close = 0;

    // Right to left pass
    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === '(') {
            open++;
        } else {
            close++;
        }

        if (open === close) {
            ans = Math.max(ans, 2 * open);
        } else if (open > close) {
            open = close = 0;
        }
    }

    return ans;
};
