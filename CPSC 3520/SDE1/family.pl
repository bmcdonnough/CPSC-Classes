% Parent Facts
% First Gen
parent(robert, alice).
parent(linda, alice).
parent(robert, michael).
parent(linda, michael).
parent(robert, mark).
parent(linda, mark).

% Second Gen
parent(alice, jake).
parent(bob, jake).
parent(alice, emma).
parent(bob, emma).

parent(michael, nancy).
parent(sarah, nancy).
parent(michael, tom).
parent(sarah, tom).

parent(mark, john).
parent(chloe, john).
parent(mark, lisa).
parent(chloe, lisa).

% Thrid Gen
parent(nancy, peter).
parent(nancy, amy).

% Marraige Facts
married(robert, linda).
married(bob, alice).
married(michael, sarah).
married(mark, chloe).

% Male Facts
male(robert).
male(bob).
male(michael).
male(mark).
male(jake).
male(tom).
male(john).
male(peter).

% Female Facts
female(linda).
female(alice).
female(sarah).
female(chloe).
female(emma).
female(nancy).
female(lisa).
female(amy).

% Age Facts
age(robert, 68).
age(linda, 65).
age(alice, 42).
age(bob, 44).
age(michael, 41).
age(sarah, 42).
age(mark, 45).
age(chloe, 43).
age(jake, 15).
age(emma, 12).
age(nancy, 20).
age(tom, 10).
age(john, 20).
age(lisa, 17).
age(peter, 2).
age(amy, 1).

% Rules

% Sibling Rule
sibling(Person1, Person2) :- 
    setof(Parent, (parent(Parent, Person1), parent(Parent, Person2)),_),
    Person1 \= Person2.

% Grandparent Rule
grandparent(Grandparent, Grandchild) :- 
    parent(Grandparent, Parent), 
    parent(Parent, Grandchild).

% Cousin Rule
cousin(Person1, Person2) :- 
    parent(Parent1, Person1), 
    parent(Parent2, Person2), 
    sibling(Parent1, Parent2), 
    Parent1 \= Parent2.

% Uncle and Aunt Rule
uncle(Uncle, Child) :- 
    sibling(Uncle, Parent),    
    parent(Parent, Child), 
    male(Uncle).

aunt(Aunt, Child) :- 
    sibling(Aunt, Parent), 
    parent(Parent, Child), 
    female(Aunt).

% Ancestor Rule
ancestor(Ancestor, Descendant) :- 
    parent(Ancestor, Descendant);
    parent(Ancestor, Intermidiate), 
    ancestor(Intermidiate, Descendant). 

% Older Sibling Rule
older_sibling(Older, Younger) :-
    sibling(Older, Younger),
    age(Older, Age1),
    age(Younger, Age2),
    Age1 > Age2.

% Bigger Brother / Bigger Sister Rules
bigger_brother(Brother, Sibling) :-
    male(Brother),
    older_sibling(Brother, Sibling).

bigger_sister(Sister, Sibling) :-
    female(Sister),
    older_sibling(Sister, Sibling).

% In-Law Rules
brother_in_law(BrotherInLaw, Person) :-
    married(Spouse, Person),
    sibling(BrotherInLaw, Spouse),
    male(BrotherInLaw);

    sibling(Sibling, Person),
    married(BrotherInLaw, Sibling),
    male(BrotherInLaw).
    
sister_in_law(SisterInLaw, Person) :-
    married(Spouse, Person),
    sibling(SisterInLaw, Spouse),
    female(SisterInLaw);

    sibling(Sibling, Person),
    married(SisterInLaw, Sibling),
    female(SisterInLaw).

% Ancestor Rules

% Nth Ancestor
nth_ancestor(1, Ancestor, Person) :-
    parent(Ancestor, Person).

nth_ancestor(N, Ancestor, Person) :-
    N > 1,
    parent(Parent, Person),
    N1 is N - 1,
    nth_ancestor(N1, Ancestor, Parent).

% Common Ancestor
common_ancestor(Person1, Person2, Ancestor) :-
    ancestor(Ancestor, Person1),
    ancestor(Ancestor, Person2),
    Person1 \= Person2.

% Common Ancestor
common_ancestors(Person1, Person2, AncestorList) :-
    findall(Ancestor, common_ancestor(Person1, Person2, Ancestor), AncestorList).
    