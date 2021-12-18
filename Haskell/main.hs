import Text.Printf
import Control.Exception
import System.CPUTime
import System.Random
import Data.List

main = do
    seed  <- newStdGen
    let rs = randomlist 1000000 seed

    putStrLn "Starting..."
    time $ qsort rs `seq` return ()
    putStrLn "Done."

randomlist :: Int -> StdGen -> [Int]
randomlist n = take n . unfoldr (Just . random)
       
qsort :: (Ord a) => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort [a | a <- xs, a < x]
                      ++ [x] ++
               qsort [b | b <- xs, b >= x]

time :: IO t -> IO t
time a = do
    start <- getCPUTime
    v <- a
    end   <- getCPUTime
    let diff = (fromIntegral (end - start)) / (10^12)
    printf "Computation time: %0.3f sec\n" (diff :: Double)
    return v

