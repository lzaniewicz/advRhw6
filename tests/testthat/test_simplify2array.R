expect_equivalent(simplify2array(list(1,2,3,4)), matrix(1:4, ncol=1))
expect_equivalent(simplify2array(list(c(1,2), c(3,4)), matrix(1:4, ncol=2))
expect_error(simplify2array(list("asdf")))
expect_is(simplify2array(matrix(1,3,4)), class="matrix")
expect_error(simplify2array(list( c(1,2), c("a","b"))))

