(* This function is used to find the first duplicate in a list. It is the helper function
   for the first_duplicate function*)
let rec first_duplicate_helper seen lst =
  match lst with
  | [] -> -10000
  | h :: t ->
    if List.mem h seen then h
    else first_duplicate_helper (h :: seen) t

(* Finds the first duplicate in a list. Uses the first_duplicate_helper function to do this*)
let first_duplicate (lst : int list) = first_duplicate_helper [] lst

(* Counts the occurances of each item in a list. Helper function for first_nonrepeating *)
let rec count_occurrences x lst =
  match lst with
  | [] -> 0
  | h :: t -> (if h = x then 1 else 0) + count_occurrences x t

(* Removes all the occurances of a number in the list provided *)
let rec remove x lst = 
  match lst with 
  | [] -> []
  | h :: t -> if x = h then remove x t else h :: remove x t

(* Used to find teh first nonrepeating number in a list *)
let rec first_nonrepeating (lst: int list) =
  match lst with
  | [] -> -10000
  | h :: t -> 
    if count_occurrences h lst = 1 then h
    else first_nonrepeating (remove h lst)

(* Used to determin if x + any number from lst are equal to v *)
let rec exists_sum v x lst =
  match lst with
  | [] -> false
  | h :: t -> if x + h = v then true else exists_sum v x t

(* Function that sees if any two numbers from two lists add to a third number *)
let rec sumOfTwo ((a: int list), (b: int list), (v : int)) = 
  match a with
  | [] -> false
  | h :: t -> if exists_sum v h b then true else sumOfTwo (t, b, v)

(* Takes in a list and returns the first n items from the list *)
let rec take (n, lst) =
  match (n, lst) with
  | (n, _) when n <= 0 -> []
  | (_, []) -> []
  | (n, h :: t) -> h :: take (n-1, t)

(* Takes in a list and drops the first n items from the list *)
let rec drop (n, lst) =
  match (n, lst) with
  | (n, _) when n < 0 -> []
  | (n, _) when n = 0 -> lst
  | (_, []) -> []
  | (n, _ :: t) -> drop (n-1, t)

(* Returns every possible powerset from a given list *)
let rec powerset = function
  | [] -> [[]]
  | h :: t ->
    List.append (powerset t) (List.map (fun subset -> h :: subset) (powerset t))
