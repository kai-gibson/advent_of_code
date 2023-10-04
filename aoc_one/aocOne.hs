import Prelude
import Data.List.Split
import Data.Sort

main = do
    str <- readFile "./day1.txt"
    -- Part One
    print (maximum (map sum (splitOn [0] (
            [if x /= "" 
                then read x :: Integer 
                else 0 | x<- lines str]))))

    -- Part Two
    print (sum (take 3 (reverse (sort (map sum (splitOn [0] (
            [if x /= "" 
                then read x :: Integer 
                else 0 | x<- lines str])))))))
