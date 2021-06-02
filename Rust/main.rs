use std::time::{SystemTime};

const CANT_ELEM  : i32 = 100000000;
const LIST_NUM : i32 = 0;
const SRCH_NUM : i32 = 1;


//Funcion de buscar en la lista en rush
pub fn linear_search<T: PartialEq>(item: &T, arr: &[T]) -> i32 {
    let mut idx_pos = -1; // -1 indicates not found

    for (idx, data) in arr.iter().enumerate() {
        if item == data {
            idx_pos = idx as i32;
            return idx_pos;
        }
    }
    idx_pos
}

//FUNCION MAIN
fn main() {

    let mut ys: [u64; 10000] = [0; 10000];

    let inicio = SystemTime::now();

    let index = linear_search(&23, &ys); //Recorre toda la lista pero no encuentra nada
    println!("Posicion: {}", index);   

    let fin = SystemTime::now();
    println!("Duracion: {:?}", fin.duration_since(inicio))
 
}