#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


void cavity_flow_pyccel(int64_t nt, t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, t_ndarray b, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, t_ndarray pn, int64_t rho, double nu, int64_t nit);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *cavity_flow_pyccel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t nt;
    t_ndarray u = {.shape = NULL};
    t_ndarray un = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    t_ndarray vn = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    double dt;
    int64_t nx;
    int64_t ny;
    double dx;
    double dy;
    t_ndarray p = {.shape = NULL};
    t_ndarray pn = {.shape = NULL};
    int64_t rho;
    double nu;
    int64_t nit;
    PyObject *nt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *un_tmp;
    PyArrayObject *v_tmp;
    PyArrayObject *vn_tmp;
    PyArrayObject *b_tmp;
    PyObject *dt_tmp;
    PyObject *nx_tmp;
    PyObject *ny_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *p_tmp;
    PyArrayObject *pn_tmp;
    PyObject *rho_tmp;
    PyObject *nu_tmp;
    PyObject *nit_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "nt",
        "u",
        "un",
        "v",
        "vn",
        "b",
        "dt",
        "nx",
        "ny",
        "dx",
        "dy",
        "p",
        "pn",
        "rho",
        "nu",
        "nit",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO!O!O!O!O!OOOOOO!O!OOO", kwlist, &nt_tmp, &PyArray_Type, &u_tmp, &PyArray_Type, &un_tmp, &PyArray_Type, &v_tmp, &PyArray_Type, &vn_tmp, &PyArray_Type, &b_tmp, &dt_tmp, &nx_tmp, &ny_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &p_tmp, &PyArray_Type, &pn_tmp, &rho_tmp, &nu_tmp, &nit_tmp))
    {
        return NULL;
    }
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(un_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        un = pyarray_to_ndarray(un_tmp);
    }
    if (!pyarray_check(v_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        v = pyarray_to_ndarray(v_tmp);
    }
    if (!pyarray_check(vn_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        vn = pyarray_to_ndarray(vn_tmp);
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeInt(nx_tmp))
    {
        nx = PyInt64_to_Int64(nx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(ny_tmp))
    {
        ny = PyInt64_to_Int64(ny_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (!pyarray_check(pn_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        pn = pyarray_to_ndarray(pn_tmp);
    }
    if (PyIs_NativeInt(rho_tmp))
    {
        rho = PyInt64_to_Int64(rho_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(nu_tmp))
    {
        nu = PyDouble_to_Double(nu_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeInt(nit_tmp))
    {
        nit = PyInt64_to_Int64(nit_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    cavity_flow_pyccel(nt, u, un, v, vn, b, dt, nx, ny, dx, dy, p, pn, rho, nu, nit);
    result = Py_BuildValue("");
    free_pointer(u);
    free_pointer(un);
    free_pointer(v);
    free_pointer(vn);
    free_pointer(b);
    free_pointer(p);
    free_pointer(pn);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_1qjq853iok9y_1qjq853iok9y_methods[] = {
    {
        "cavity_flow_pyccel",
        (PyCFunction)cavity_flow_pyccel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_1qjq853iok9y_1qjq853iok9y_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_1qjq853iok9y_1qjq853iok9y_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_1qjq853iok9y_1qjq853iok9y",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_1qjq853iok9y_1qjq853iok9y_methods,
    mod_1qjq853iok9y_1qjq853iok9y_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_1qjq853iok9y_1qjq853iok9y(void)
{
    import_array();
    return PyModuleDef_Init(&mod_1qjq853iok9y_1qjq853iok9y_module);
}
