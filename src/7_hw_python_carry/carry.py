def curry(func, arity):
    """
    func: исходная функция
    arity: арность функции
    return каррированная функция
    """
    if not isinstance(arity, int) or arity < 0:
        raise ValueError(f"Арность должна быть неотрицательным целым числом, получено: {arity}")
    if arity == 0:
        return lambda: func()
    def curried(*args):
        if len(args) >= arity:
            return func(*args[:arity])
        else:
            def next_curried(*next_args):
                return curried(*(args + next_args))
            return next_curried
    return curried


def uncurry(curried_func, arity):
    if not isinstance(arity, int) or arity < 0:
        raise ValueError(f"Арность должна быть неотрицательным целым числом, получено: {arity}")
    def uncurried(*args):
        if len(args) != arity:
            raise ValueError(f"Ожидается {arity} аргументов, получено: {len(args)}")
        result = curried_func
        for arg in args:
            result = result(arg)
        return result
    return uncurried

def sum3(x, y, z):
    return x * y * z

sum3_curry = curry(sum3, 3)
sum3_uncurry = uncurry(sum3_curry, 3)
print(sum3_curry(1)(2)(6))
print(sum3_uncurry(1, 2, 5))
