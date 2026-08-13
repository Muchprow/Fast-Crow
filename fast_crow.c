#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string.h>
#include <ctype.h>

static PyObject* fast_clean_val(PyObject* self, PyObject* args) {
    const char* str;
    if (!PyArg_ParseTuple(args, "s", &str)) {
        return NULL;
    }

    char clean[1024];
    int j = 0;
    for (int i = 0; str[i] != '\0' && str[i] != ';'; i++) {
        clean[j++] = str[i];
    }
    clean[j] = '\0';

    char *start = clean;
    while(isspace((unsigned char)*start) || *start == '"' || *start == '\'') start++;

    if(*start == 0) return PyUnicode_FromString("");

    char *end = start + strlen(start) - 1;
    while(end > start && (isspace((unsigned char)*end) || *end == '"' || *end == '\'')) end--;
    end[1] = '\0';

    return PyUnicode_FromString(start);
}

static PyMethodDef FastCrowMethods[] = {
    {"clean_val", fast_clean_val, METH_VARARGS, "Ultra-fast C string cleaner for Python"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef fastcrowmodule = {
    PyModuleDef_HEAD_INIT,
    "fast_crow",
    "High-performance C library for Python",
    -1,
    FastCrowMethods
};

PyMODINIT_FUNC PyInit_fast_crow(void) {
    return PyModule_Create(&fastcrowmodule);
}