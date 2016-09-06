data Node a = NullNode
            | Node {
                left :: Node a,
                right :: Node a,
                value :: a
            }

listify :: Node a -> [a]
listify NullNode = []
listify (Node l r v) = (listify l)++(v:(listify r))

mknode :: a -> Node a
mknode v = Node NullNode NullNode v

insert :: Ord a => Node a -> Node a -> Node a
insert NullNode i = i
insert (Node l r v) i | value i < v = Node (insert l i) r v
                      | otherwise   = Node l (insert r i) v

insertValue :: Ord a => Node a -> a -> Node a
insertValue root v = insert root (mknode v)

insertValues :: Ord a => Node a -> [a] -> Node a
insertValues root = foldl insertValue root

merge :: Node a -> Node a -> Node a
merge
