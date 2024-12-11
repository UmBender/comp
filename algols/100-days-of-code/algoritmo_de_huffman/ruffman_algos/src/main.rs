use std::cmp::Ordering;
use std::collections::BTreeMap;

#[derive(Debug)]
struct Node {
    counter: usize,
    name: Option<char>,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        return self.right == other.right
            && self.left == other.left
            && self.name == other.name
            && self.counter == other.counter;
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        self.counter.partial_cmp(&other.counter)
    }
}

impl Clone for Node {
    fn clone(&self) -> Self {
        return Self {
            counter: self.counter,
            name: self.name,
            left: self.left.clone(),
            right: self.right.clone(),
        };
    }
}

impl Eq for Node {}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        self.counter.partial_cmp(&other.counter).unwrap()
    }
}

impl Node {
    /*
     * Cria um novo nó com nenhuma definição
     */
    fn new() -> Self {
        return Self {
            counter: 0,
            name: Option::None,
            left: Option::None,
            right: Option::None,
        };
    }

    /*
     * Cria um novo nó com um contador de frequência e com o caractér em si
     */
    fn from(counter: usize, name: char) -> Self {
        return Self {
            counter,
            name: Option::Some(name),
            left: Option::None,
            right: Option::None,
        };
    }

    /*
     * Cria um nó novo com sendo pai de outros dois nós passados por parâmetro
     */
    fn new_parent(left: Self, right: Self) -> Self {
        if Self::new() == right {
            return left;
        }
        return Self {
            counter: left.counter + right.counter,
            name: Option::None,
            left: Option::Some(Box::new(left)),
            right: Option::Some(Box::new(right)),
        };
    }

    /*
     * É uma implementação para mostrar a árvore em ordem
     */
    fn show(&self) {
        match &self.left {
            Some(i) => i.show(),
            None => (),
        }
        println!("{}", self.counter);
        match &self.right {
            Some(i) => i.show(),
            None => (),
        }
    }
}

struct MinHeap {
    array: Vec<Box<Node>>,
}

impl MinHeap {
    /*
     * Cria um minimal heap para nós vazio
     */
    fn new() -> Self {
        return MinHeap {
            array: vec![Box::new(Node::new())],
        };
    }

    /*
     * Cria um minimal heap para nós com base em um vetor de nós
     */
    fn from(list_nodes: &Vec<Node>) -> Self {
        let mut list: Vec<Node> = vec![Node::new()];
        for i in list_nodes {
            list.push(i.clone());
        }
        list.sort();
        let mut lista = vec![Box::new(Node::new())];
        list.iter().for_each(|x| lista.push(Box::new(x.clone())));
        return Self { array: lista };
    }

    /*
     * Pega o menor valor do heap
     */
    fn get_val(&mut self) -> Box<Node> {
        let top = self.array[1].clone();
        self.array[1] = self.array[self.array.len() - 1].clone();
        self.array.pop();
        let mut position: usize = 1;
        while 2 * position + 1 < self.array.len()
            && (self.array[2 * position] > self.array[position]
                || self.array[2 * position + 1] > self.array[position])
        {
            if self.array[2 * position] > self.array[position] {
                let holder = self.array[2 * position + 1].clone();
                self.array[2 * position + 1] = self.array[position].clone();
                self.array[position] = holder;
                position *= 2;
                position += 1;
            } else {
                let holder = self.array[2 * position].clone();
                self.array[2 * position] = self.array[position].clone();
                self.array[position] = holder;
                position *= 2;
            }
        }
        return top;
    }

    /*
     * Insere um novo nó no heap
     */
    fn insert_val(&mut self, node: Box<Node>) -> () {
        let mut position: usize = self.array.len();
        self.array.push(node);
        while position > 0 && self.array[position] < self.array[position / 2] {
            let holder = self.array[position].clone();
            self.array[position] = self.array[position / 2].clone();
            self.array[position / 2] = holder;
            position /= 2;
        }
    }

    /*
     * Pega o tamanho do heap
     */
    fn len(&self) -> usize {
        return self.array.len() - 1;
    }
}

/*
 * Árvore que representa o código de huffman
 */
struct Tree {
    root: Option<Box<Node>>,
    size: usize,
    convert_tree: BTreeMap<char, String>,
    number_letters: usize,
    heap: MinHeap,
}

impl Tree {
    /*
     * Gera um mapa dos caracteres com sua frequencias
     */
    fn gen_freq_table(text: &String) -> (BTreeMap<usize, Vec<char>>, usize) {
        let mut my_map: BTreeMap<char, usize> = BTreeMap::new();
        let mut counter: usize = 0;
        for i in text.chars() {
            match my_map.get(&i) {
                None => {
                    let _ = my_map.insert(i, 1);
                    counter += 1;
                }
                Some(n) => {
                    let _ = my_map.insert(i, n + 1);
                }
            }
        }
        let mut by_frequecy: BTreeMap<usize, Vec<char>> = BTreeMap::new();
        for (k, v) in my_map.iter() {
            match by_frequecy.get_mut(v) {
                None => {
                    let _ = by_frequecy.insert(*v, vec![*k]);
                }
                Some(vector) => {
                    vector.push(*k);
                }
            }
        }
        return (by_frequecy, counter);
    }

    /*
     * Constroi uma árvore vazia que representa a árvore de huffman
     */
    fn new() -> Self {
        return Tree {
            root: Option::None,
            size: 0,
            convert_tree: BTreeMap::new(),
            number_letters: 0,
            heap: MinHeap::new(),
        };
    }

    /*
     * Constroi uma árvore que representa o código de huffman com base em um texto entregue
     */
    fn build(&mut self, text: &String) {
        let (tree, number_letters) = Self::gen_freq_table(&text);
        let mut heap = MinHeap::new();
        for (i, j) in tree.iter() {
            for k in j.iter() {
                let node = Node::from(*i, *k);
                heap.insert_val(Box::new(node));
            }
        }
        while heap.len() > 1 {
            let left = heap.get_val();
            let right = heap.get_val();
            let new_node = Node::new_parent((*left).clone(), (*right).clone());
            heap.insert_val(Box::new(new_node));
        }
        self.root = Option::Some(heap.get_val());
    }
    fn base_populate(&mut self) {
        self.populate(self.root.clone().unwrap(), String::from(""));
    }

    fn populate(&mut self, actual: Box<Node>, acc: String) {
        match actual.name {
            Some(i) => {
                let _ = self.convert_tree.insert(i, acc);
            }
            None => {
                self.populate(actual.left.unwrap().clone(), format!("{}{}", acc, '0'));
                self.populate(actual.right.unwrap().clone(), format!("{}{}", acc, '1'));
            }
        }
    }

    fn convert(&self, word: &String) -> Vec<String> {
        let mut v = vec![];
        for i in word.chars() {
            v.push(self.convert_tree.get(&i).unwrap().clone());
        }
        return v;
    }

    fn deconvert(&mut self, info: String) -> String {
        let mut word: String = String::new();
        let mut root_node: Box<Node> = self.root.clone().unwrap();
        for j in info.chars() {
            match root_node.name {
                Some(i) => {
                    println!("{i}");
                    word = format!("{}{}", word, i);
                    root_node = self.root.clone().unwrap();
                }
                None => {}
            }
            if j == '1' {
                root_node = root_node.left.clone().unwrap();
            } else {
                root_node = root_node.right.clone().unwrap();
            }
        }
        //        word = format!("{}{}", word, root_node.name.unwrap());

        return word;
    }

    fn show(&self) {}
}

fn main() {
    let mut huff = Tree::new();
    huff.build(&mut String::from("aabbaabbcccc"));
    huff.base_populate();
    huff.root.clone().unwrap().show();
    let caps = huff.convert(&mut String::from("aa"));
    for i in caps.iter() {
        println!("{}", i);
    }
    for (i, j) in huff.convert_tree.iter() {
        println!("{}{}", i, j);
    }
    for i in caps.iter() {
        println!("{}", i);
    }
    let mut word: String = String::new();
    for i in caps {
        word = format!("{}{}", word, i);
    }
    huff.show();
    let palavra_descomprimida = huff.deconvert(word);
    println!("Descomprimida: {}", palavra_descomprimida);
}
