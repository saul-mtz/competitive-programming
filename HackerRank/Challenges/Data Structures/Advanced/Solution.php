<?php

/**
 * Solves the "Cube Summation" problem using the an Octree
 *
 * @link https://www.hackerrank.com/challenges/cube-summation
 */
class OctreeNode {

    public $value = 0;
    protected $dimmension;
    protected $childrenDimmensions;
    protected $children = [];
    protected $from;
    protected $to;

    /**
     * Tree node constructor
     *
     * @param $n
     * @param $from
     * @param $to
     */
    function __construct($n, $from, $to) {
        $this->dimmension = $n;
        $this->from       = $from;
        $this->to         = $to;

        // children nodes if it is not a leaf
        if ($n > 1) {
            $childDimm = $n/2;
            list($fromX, $fromY, $fromZ) = $from;
            list($toX, $toY, $toZ) = $to;

            // it does not create the child nodes, just save the references for lazy loading
            $this->childrenDimmensions = [
                [[$fromX,$fromY,$fromZ], [$toX-$childDimm,$toY-$childDimm,$toZ-$childDimm]],
                [[$fromX+$childDimm,$fromY,$fromZ], [$toX,$toY-$childDimm,$toZ-$childDimm]],
                [[$fromX,$fromY+$childDimm,$fromZ], [$fromX+$childDimm-1,$toY,$toZ-$childDimm]],
                [[$fromX+$childDimm,$fromY+$childDimm,$fromZ], [$toX,$toY,$toZ-$childDimm]],
                [[$fromX,$fromY,$fromZ+$childDimm], [$toX-$childDimm,$toY-$childDimm,$toZ]],
                [[$fromX+$childDimm,$fromY,$fromZ+$childDimm], [$toX,$toY-$childDimm,$toZ]],
                [[$fromX,$fromY+$childDimm,$fromZ+$childDimm], [$fromX+$childDimm-1,$toY,$toZ]],
                [[$fromX+$childDimm,$fromY+$childDimm,$fromZ+$childDimm], [$toX,$toY,$toZ]]
            ];
        }
    }


    /**
     * Performs the update operation
     *
     * @param $coordinate
     * @param $value
     * @return int
     */
    function update($coordinate, $value) {

        if (1 == $this->dimmension) {
            // if this node contains the coordinate to update
            if ($coordinate == $this->from) {
                $this->value = $value;
            }
        }

        // if the coordinate to update is within this cube
        else if ($this->in($coordinate)) {
            foreach ($this->childrenDimmensions as $childDimm) {
                if ($this->inChild($childDimm[0], $childDimm[1], $coordinate)) {
                    $this->value += $this->getChild($childDimm)->update($coordinate, $value);
                }
            }
            $this->value = 0;
            foreach ($this->children as $child) {
                $this->value += $child->value;
            }
        }

        return $this->value;
    }

    /**
     * Try to get a child for an specific range, if it does not exists then create it
     *
     * @param $coords
     * @return mixed
     */
    function getChild($coords) {
        $from = $coords[0];
        $to = $coords[1];
        $key = "{$from[0]},{$from[1]},{$from[2]},{$to[0]},{$to[1]},{$to[2]}";
        if (!array_key_exists($key, $this->children)) {
            $this->children[$key] = new OctreeNode($this->dimmension/2, $from, $to);
        }
        return $this->children[$key];
    }

    /**
     * Calculates the sum of the elements in the range given
     *
     * @param $from
     * @param $to
     * @return int
     */
    function query($from, $to) {
        switch (true) {
            // the current range is in the query one
            case ($from[0] <= $this->from[0] && $to[0] >= $this->to[0] &&
                  $from[1] <= $this->from[1] && $to[1] >= $this->to[1] &&
                  $from[2] <= $this->from[2] && $to[2] >= $this->to[2]):
                return $this->value;

            // the range overlaps, so calculate the sum of the overlapping fragments
            case ($this->in($from) || $this->in($to)):
                $sum = 0;
                foreach($this->children as $child) {
                    $sum += $child->query($from, $to);
                }
                return $sum;

            default:
                return 0;
        }
    }

    /**
     * Validate if the value received as parameter is contained in this cube
     *
     * @param $coordinate
     * @return bool
     */
    protected function in($coordinate) {
        return
            ($coordinate[0] >= $this->from[0] && $coordinate[0] <= $this->to[0]) ||
            ($coordinate[1] >= $this->from[1] && $coordinate[1] <= $this->to[1]) ||
            ($coordinate[2] >= $this->from[2] && $coordinate[2] <= $this->to[2]);
    }

    /**
     * Validates if $coordinate is within the cube [$from, $to]
     *
     * @param $from
     * @param $to
     * @param $coordinate
     * @return bool
     */
    protected function inChild($from, $to, $coordinate) {
        return
            ($coordinate[0] >= $from[0] && $coordinate[0] <= $to[0]) &&
            ($coordinate[1] >= $from[1] && $coordinate[1] <= $to[1]) &&
            ($coordinate[2] >= $from[2] && $coordinate[2] <= $to[2]);
    }
}


// test cases
fscanf(STDIN, "%d", $cases);

while ($cases-- > 0) {
    // read the integer values for N and m
    fscanf(STDIN, "%d %d", $n, $m);

    $log2 = log($n)/log(2);

    // the dimmension of the tree is the closest number of the way 2^n which is >= $n
    $dimmension = pow(2, ceil($log2));

    // create an Octree of dimmension $n
    $octree = new OctreeNode($dimmension, [1,1,1], [$dimmension,$dimmension,$dimmension]);

    while ($m-- > 0) {
        $parts = explode(' ', trim(fgets(STDIN)));
        if ('UPDATE' === $parts[0]) {
            $octree->update([$parts[1],$parts[2], $parts[3]], $parts[4]);
        } else {
            echo $octree->query([$parts[1],$parts[2], $parts[3]], [$parts[4],$parts[5], $parts[6]]) . PHP_EOL;
        }
    }
}
