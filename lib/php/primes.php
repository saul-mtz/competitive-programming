<?php

function generate($b)
{
    $primes = [1,2];
    for ($k = 3; $k <= $b; $k += 2) {
        $aux = sqrt($k);
        $i = 0;
        $isPrime = false;
        while (($primes[$i] <= $aux) && ($i < count($primes))) {
            if (!($k % $primes[$i ++])) {
                $isPrime = true;
                break;
            }
        }

        if ($isPrime) {
            $primes[] = $k;
            echo $k . ',';
        }
    }

    return $primes;
}

generate(10000000);
echo PHP_EOL;