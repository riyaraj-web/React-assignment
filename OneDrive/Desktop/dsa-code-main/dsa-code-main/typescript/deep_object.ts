type AnyObject = Record<string, any>;

function flattenObject(obj: AnyObject, parentKey = '', result: AnyObject = {}): AnyObject {
    for (const key in obj) {
        if (!obj.hasOwnProperty(key)) continue;
        const newKey = parentKey ? `${parentKey}.${key}` : key;
        if (obj[key] && typeof obj[key] === 'object' && !Array.isArray(obj[key])) {
            flattenObject(obj[key], newKey, result);
        } else {
            result[newKey] = obj[key];
        }
    }
    return result;
}

// Usage
const input = { a: { b: { c: 1 } }, d: 2 };
console.log(flattenObject(input)); // { 'a.b.c': 1, d: 2 }
