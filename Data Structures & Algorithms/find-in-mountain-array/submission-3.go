/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */

func findInMountainArray(target int, mountainArr *MountainArray) int {
    pvt := findPivot(mountainArr)
    n := mountainArr.length()
    if mountainArr.get(pvt) == target {
        return pvt
    }

    fmt.Printf("pivot: %v\n", pvt)

    l := leftSearch(mountainArr, target, 0, pvt)
    if l != nil {
        return *l
    }

    r := rightSearch(mountainArr, target, pvt, n-1)
    if r != nil {
        return *r
    }

    return -1
}

func leftSearch(arr *MountainArray, target, l, r int) *int {
    
    for l < r {
        m := l + (r - l)/2
        if target <= arr.get(m) {
            r = m
        } else {
            l = m + 1
        }
    }

    if arr.get(l) == target {
        return &l
    }

    return nil
}

func rightSearch(arr *MountainArray, target, l, r int) *int {

    for l < r {
        m := l + (r - l)/2
        if target >= arr.get(m) {
            r = m
        } else {
            l = m + 1
        }
    }

    if arr.get(l) == target {
        return &l
    }

    return nil
}

func findPivot(arr *MountainArray) int {
    n := arr.length()

    l := 0
    r := n-1

    for l < r {
        m := l + (r - l)/2

        if arr.get(m) > arr.get(m + 1) {
            r = m
        } else {
            l = m + 1
        }
    }

    return l
}


