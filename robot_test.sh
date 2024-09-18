echo "Test X: (shortest distance, number of paths)"
echo "TEST 1: (2,2)"
./greedy_robot 1 3 4 4 3
echo "TEST 2: (Already there)"
./greedy_robot 2 1 1 1 1
echo "TEST 3: (NP, 0)"
./greedy_robot 1 1 1 5 1

echo "Test 4: (3, 1)" # Tests simple northward movement with no obstacles.
./greedy_robot 10 0 0 0 3

echo "Test 5: (3, 1)" # Tests simple eastward movement with no obstacles.
./greedy_robot 10 0 0 3 0

echo "Test 6: (4, 6)" # Tests diagonal movement with multiple possible paths.
./greedy_robot 10 0 0 2 2

echo "Test 7: (NP, 0)" # Tests northward movement blocked by max distance limit.
./greedy_robot 2 0 0 0 5

echo "Test 8: (NP, 0)" # Tests eastward movement blocked by max distance limit.
./greedy_robot 1 0 0 5 0

echo "Test 9: (50, 1)" # Tests long straight movement to check distance handling.
./greedy_robot 100 0 0 0 50

echo "Test 10: (10, 252)" # Tests a complex route with turns to check multiple path handling.
./greedy_robot 10 0 0 5 5

echo "Test 11: (Already there)" # Checks the scenario when the robot starts at the treasure location.
./greedy_robot 5 5 5 5 5

echo "Test 12: (NP, 0)" # Tests a scenario where the treasure is too far to reach within the max distance.
./greedy_robot 3 0 0 0 10

echo "Test 13: (6, 20)" # Tests a moderately complex diagonal path with sufficient max distance.
./greedy_robot 15 0 0 3 3

echo "Test 14: (2, 2)" # Tests minimal movement with exact maximum distance allowance.
./greedy_robot 3 0 0 1 1

echo "Test 15: (10, 252)" # Tests complex movements near the conceptual grid boundaries.
./greedy_robot 10 -5 -5 -10 -10

echo "Test 16: (6, 20)" # Tests alternative path finding with enough distance for several turns.
./greedy_robot 5 1 1 4 4

echo "Test 17: (4, 6)" # Tests for path duplication checking in a scenario with multiple valid routes.
./greedy_robot 10 0 0 2 2
