import Data.List.Split
import Data.Sort

main = do
    str <- readFile "./day1.txt"
    
    let list = reverse (sort (map sum $ 
            [[read y::Int | y<-x] | x<-splitOn [""] (lines str)]))
    
    print (head list); print (sum (take 3 list))
