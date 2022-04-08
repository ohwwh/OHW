const toDoForm = document.querySelector("#todo-form");
const toDoList = document.querySelector("#todo-list");
const toDoInput = toDoForm.querySelector("input");
let toDos = [];

/*function removeByID(item){
    if (item.id == li.id)
        return false;
    else
        return true;
}*/

function saveToDos(event){
    localStorage.setItem("todos", JSON.stringify(toDos));
}

function deleteToDo(event){
    const li = event.target.parentElement;
    toDos = toDos.filter(item => item.id != li.id);
    //localStorage.removeItem("todos");
    saveToDos();
    li.remove();
}

function paintToDo(newToDo){
    const li = document.createElement("li");
    const span = document.createElement("span");
    const button = document.createElement("button");
    li.appendChild(span);
    li.appendChild(button);
    span.innerText = newToDo.text;
    li.id = newToDo.id;
    button.innerText = "❌";
    button.addEventListener("click", deleteToDo);
    toDoList.appendChild(li);
}

function handleToDoSubmit(event){
    event.preventDefault();
    const newToDo = toDoInput.value;
    toDoInput.value="";
    const newToDoObj = {
        text:newToDo,
        id:Date.now(),
    };
    toDos.push(newToDoObj);
    paintToDo(newToDoObj)
    saveToDos();
}

toDoForm.addEventListener("submit", handleToDoSubmit);


const savedToDos = localStorage.getItem("todos");
if (savedToDos != null){
    toDos = JSON.parse(savedToDos);
    toDos.forEach((item) => paintToDo(item));
}

