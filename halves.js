function halv_array_swap(iarra) {
  if (((iarra.length)%2)!=0)
    {
    return false;
    }

  for (var i = 0; i < iarra.length / 2; i++) {
    var tmp = iarra[i];
    iarra[i] = iarra[i + iarra.length / 2];
    iarra[i + iarra.length / 2] = tmp;
  }
  return iarra;
}

console.log(halv_array_swap([1,2,3,4,5,6]))
console.log(halv_array_swap([1,2,3,4,5,6,7]))
