export let printbuff = function (formatted, buffer) {
    // buffer E { "output", "warn", "error" }
    // print all input onto console
    console.log(formatted);
};

export let promptinput = function (optional) {
    alert(optional);
    console.log(optional);

    let input = document.getElementById("input");
    if (input == null || input == undefined) return;

    input.addEventListener("input", (event) => { printbuff(event.data, "output") });
}

export const standard = {
    output: function (format) {
        // todo: format string
        printbuff(format, "output");
    },
    error: function (format) {
        // todo: format string
        printbuff(format, "error");
    },
    input: function (input) {
        // guess the todo
        promptinput(input);
    }
};
