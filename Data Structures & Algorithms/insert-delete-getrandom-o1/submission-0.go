type RandomizedSet struct {
    s map[int]interface{}
}

func Constructor() RandomizedSet {
    m := make(map[int]interface{})

    return RandomizedSet{
        s: m,
    }
}

func (this *RandomizedSet) Insert(val int) bool {
    _, ok := this.s[val]

    if ok {
        return false
    }

    this.s[val] = struct{}{}
    return true
}

func (this *RandomizedSet) Remove(val int) bool {
    _, ok := this.s[val]

    if ok {
        delete(this.s, val)
        return true
    }

    return false
}

func (this *RandomizedSet) GetRandom() int {
    for k := range this.s {
		return k
	}
	return 0
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
 