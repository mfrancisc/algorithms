<?php

//$result = merge([1,3,5,17],[2,4,6,8]); 
$result = mergeSort([11,3,25,17,5,6,1,2],8); 

print_r($result);
function mergeSort(array $input, $len)
{
    if($len == 1) return $input;// already sorted

    $middle = floor($len / 2);
    $firsthalf = array_slice($input, 0, $middle);
    $secondhalf = array_slice($input, $middle);

    return merge( mergeSort($firsthalf, $middle), mergeSort($secondhalf, $len - $middle));

}
function merge(array $firstArray, array $secondArray)
{
    if (empty($firstArray)) {
        return $secondArray;
    }

    if (empty($secondArray)) {
        return $firstArray;
    }

    if ($firstArray[0] < $secondArray[0]) {
        $head = array_shift($firstArray);
    } else {
        $head = array_shift($secondArray);
    }

    return concat($head, merge($firstArray, $secondArray));
}

function concat($head, $result_array)
{
    $concat_array[] = $head;
    return array_merge($concat_array, $result_array);
}
