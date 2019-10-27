
total = 30

fn fib(x: int): int {
    if x <= 0 {
        return 0
    } elif x <= 2 {
        return 1
    } else {
        return fib(x - 1) + fib(x - 2)
    }
}

export {
    total = total,
}
