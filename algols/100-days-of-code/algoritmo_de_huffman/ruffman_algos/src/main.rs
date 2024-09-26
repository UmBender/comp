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

impl Node {
    fn new() -> Self {
        return Self {
            counter: 0,
            name: None,
            left: None,
            right: None,
        };
    }
    fn from(counter: usize, name: char) -> Self {
        return Self {
            counter,
            name: Option::Some(name),
            left: None,
            right: None,
        };
    }

    fn new_parent(left: Self, right: Self) -> Self {
        if Self::new() == right {
            return left;
        }
        return Self {
            counter: left.counter + right.counter,
            name: None,
            left: Option::Some(Box::new(left)),
            right: Option::Some(Box::new(right)),
        };
    }
}

struct Tree {
    root: Option<Box<Node>>,
    size: usize,
    convert_tree: BTreeMap<char, usize>,
    deconvert_tree: Vec<char>,
}

impl Tree {
    fn gen_freq_table(text: &String) -> BTreeMap<usize, Vec<char>> {
        let mut my_map: BTreeMap<char, usize> = BTreeMap::new();
        for i in text.chars() {
            match my_map.get(&i) {
                None => {
                    let _ = my_map.insert(i, 1);
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
        return by_frequecy;
    }

    fn new() -> Self {
        return Tree {
            root: Option::None,
            size: 0,
            convert_tree: BTreeMap::new(),
            deconvert_tree: vec![],
        };
    }

    fn build(&mut self, text: &String) {
        let mut actual_parent = Node::new();
        let tree = Self::gen_freq_table(&text);
        for (i, j) in tree.iter() {
            for k in j.iter() {
                actual_parent = Node::new_parent(Node::from(*i, *k), actual_parent);
            }
        }

        let mut counter: usize = 0;
        let old_parent = actual_parent.clone();

        loop {
            match actual_parent.left {
                None => {
                    self.convert_tree
                        .insert(actual_parent.name.unwrap(), counter);
                    self.deconvert_tree.push(actual_parent.name.unwrap());
                    break;
                }
                Some(i) => {
                    self.convert_tree.insert(i.name.unwrap(), counter);
                    self.deconvert_tree.push(i.name.unwrap());
                    counter += 1;
                    actual_parent = *actual_parent.right.unwrap();
                }
            }
        }
        self.size = counter;
        self.root = Option::Some(Box::new(old_parent));
    }

    fn convert(&self, word: &String) -> Vec<usize> {
        let mut state = vec![];
        for i in word.chars() {
            match self.convert_tree.get(&i) {
                None => state.push(0),
                Some(i) => state.push(*i),
            }
        }

        for i in state.iter() {
            println!("{}", i);
        }
        return state;
    }
    fn deconvert(&self, info: &Vec<usize>) -> String {
        let mut word = String::new();
        for i in info.iter() {
            let mut real_letter = 0;
            let mut clone_comp = *i;
            while clone_comp > 1 {
                real_letter += 1;
                clone_comp /= 2;
            }
            word = String::from(format!("{}{}", word, self.deconvert_tree[real_letter]));
        }
        return word;
    }

    fn show(&self) {
        for (i, j) in self.convert_tree.iter() {
            println!("{}: {}", i, j);
        }
    }
}

fn main() {
    let mut huff = Tree::new();
    huff.build(&mut String::from("aaaaaaaa"));
    let caps = huff.convert(&mut String::from("aaaaaaaa"));
    huff.show();
    let mut palavra_comprimida = vec![];
    for i in caps.iter() {
        let mut valor = 0;
        let mut pos_atual = *i;
        while pos_atual > 0 {
            valor += 1;
            valor *= 2;
            pos_atual -= 1;
        }

        palavra_comprimida.push(valor);
    }

    let palavra_descomprimida = huff.deconvert(&palavra_comprimida);
    println!("Descomprimida: {}", palavra_descomprimida);
}
