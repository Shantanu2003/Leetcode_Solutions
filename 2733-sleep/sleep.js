/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    let val = await  new Promise((resolve) =>
        setTimeout(resolve,millis));
    return val;
    }

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */